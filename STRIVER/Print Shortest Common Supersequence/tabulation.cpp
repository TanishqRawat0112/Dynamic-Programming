#include<iostream>
#include<vector>
using namespace std;

string printSCS(string x, string y){
    int n = x.length();
    int m = y.length();
    vector<vector<int> >dp(n+1,vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    string scs = "";
    while(n!=0 && m!=0){
        if(x[n-1]==y[m-1]){
            scs+=x[n-1];
            n--;
            m--;
        }
        else{
            if(dp[n][m-1]>dp[n-1][m]){
                scs+=y[m-1];
                m--;
            }
            else{
                scs+=x[n-1];
                n--;
            }
        }
    }
    while(n!=0){
        scs+=x[n-1];
        n--;
    }
    while(m!=0){
        scs+=y[m-1];
        m--;
    }

    reverse(scs.begin(),scs.end());
    return scs;
}

int main(){
    string x,y;
    cout<<"Enter the first string : ";
    cin>>x;

    cout<<"Enter the second string : ";
    cin>>y;

    string ans = printSCS(x,y);

    cout<<"The Shortest Common Supersequence will be : "<<ans<<endl;
return 0;
}