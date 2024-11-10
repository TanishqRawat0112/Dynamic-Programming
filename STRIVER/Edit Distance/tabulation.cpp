#include<iostream>
#include<vector>
using namespace std;

int editDistance(string x ,string y){
    int n = x.length();
    int m = y.length();
    vector<vector<int> >dp(n+1,vector<int>(m+1,0));

    for(int i=0;i<=n;i++){
        dp[i][0]=i;
    }
    for(int j=0;j<=m;j++){
        dp[0][j]=j;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j] = min(1+dp[i][j-1],min(1+dp[i-1][j],1+dp[i-1][j-1]));
            }
        }
    }
    return dp[n][m];
}
 
int main(){
    string x,y;
    cout<<"Enter the first string : ";
    cin>>x;

    cout<<"Enter the second string : ";
    cin>>y;

    int n = x.length();
    int m = y.length();

    int ans = editDistance(x,y);

    cout<<"The minimum operations needed will be : "<<ans<<endl;
return 0;
}