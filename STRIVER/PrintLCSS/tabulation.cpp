#include<iostream>
#include<vector>
using namespace std;

string printLCSS(string x,string y){
    int n = x.length();
    int m = y.length();
    int len = 0;
    int index =0;

    vector<vector<int> >dp(n+1,vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            if(dp[i][j]>len){
                len=dp[i][j];
                index = i;
            }
        }
    }
    string ans = "";
    for(int i = index-len;i<index;i++){
        ans+=x[i];
    }

    return ans;

}

int main(){
    string x,y;
    cout<<"Enter the first string : ";
    cin>>x;

    cout<<"Enter the second string : ";
    cin>>y;

    string ans = printLCSS(x,y);

    cout<<"The Longest Common Substring will be : "<<ans<<endl;
return 0;
}