#include<iostream>
#include<vector>
using namespace std;

int nth_fibo(int n,vector<int>&dp){
    if(n<=1)return n;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=nth_fibo(n-1,dp) + nth_fibo(n-2,dp); 
}

int fibonacci(int n){
    vector<int>dp(n+1,-1);
    return nth_fibo(n,dp);
}
 
int main(){
    int n;
    cout<<"Enter the position of the required Fibonacci number : ";
    cin>>n;

    int ans=fibonacci(n);

    cout<<"The "<<n<<"th fibonacci number is : "<<ans<<endl;
return 0;
}