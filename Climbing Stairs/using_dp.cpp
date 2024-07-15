#include<iostream>
#include<vector>
using namespace std;

int f(int n,vector<int>&dp){
    if(n<=1)return 1;
    if(dp[n]!=1e9)return dp[n];

    return dp[n]=f(n-1,dp) + f(n-2,dp);
}

int climbing_stairs(int n){
    vector<int>dp(n+1,1e9);
    return f(n,dp);
}
 
int main(){
    int n;
    cout<<"Enter the number of stairs : ";
    cin>>n;

    int ans=climbing_stairs(n);
    cout<<"The number of ways to climb the stairs will be : "<<ans<<endl;   
return 0;
}