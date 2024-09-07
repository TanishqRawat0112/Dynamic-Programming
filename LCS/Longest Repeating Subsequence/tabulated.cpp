#include<iostream>
#include<vector>
using namespace std;

int lrs(string x,string y,int n,int m,vector<vector<int> >&dp){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1] && i!=j){
                dp[i][j]=1 + dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
 
int main(){
    string x;
    cout<<"Enter the string : ";
    cin>>x;
    int n=x.size();
    vector<vector<int> >dp(n+1,vector<int>(n+1,0));

    int ans=lrs(x,x,n,n,dp);

    cout<<"The length of the longest repeating subsequence is : "<<ans<<endl;
return 0;
}