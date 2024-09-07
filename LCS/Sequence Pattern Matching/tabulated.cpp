#include<iostream>
#include<vector>
using namespace std;

int lcs(string x,string y,int n,int m,vector<vector<int> >&dp){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
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

    int n=x.length();
    int m=y.length();
    vector<vector<int> >dp(n+1,vector<int>(m+1,0));
    int ans=lcs(x,y,n,m,dp);

    if(n==ans){
        cout<<"YES , The first string is the subsequence of second string ."<<endl;
    }
    else{
        cout<<"No, the first is not the subsequence of the second string . "<<endl;
    }
return 0;
}