#include<iostream>
using namespace std;

int static dp[100][1000];

int lcs(string x,string y,int n,int m){
    if(n==0 || m==0){
        return 0;
    }
    if(dp[n][m]!=-1)return dp[n][m];
    if(x[n-1]==y[m-1]){
         dp[n][m]=1 + lcs(x,y,n-1,m-1);
    }
    else{
         dp[n][m]=max(lcs(x,y,n-1,m),lcs(x,y,n,m-1));
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

    memset(dp,-1,sizeof(dp));
 
    int ans=lcs(x,y,n,m);
    cout<<"The length of the longest common subsequence will be : "<<ans<<endl;
return 0;
}