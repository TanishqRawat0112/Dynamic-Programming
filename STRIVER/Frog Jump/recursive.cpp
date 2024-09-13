#include<iostream>
#include<vector>
using namespace std;

static int dp[100001];

int frogJump(vector<int>&stairs,int n){
    if(n==0)return 0;
    if(n==1)return abs(stairs[n]-stairs[n-1]);
    if(dp[n]!=-1)return dp[n];
    return dp[n]=min(abs(stairs[n]-stairs[n-1])+frogJump(stairs,n-1),abs(stairs[n]-stairs[n-2])+frogJump(stairs,n-2));
}

 
int main(){
    int n;
    cout<<"Enter the number of stairs : ";
    cin>>n;

    cout<<"Enter the height of each staircase : ";
    vector<int>stairs(n);
    for(int i=0;i<n;i++){
        cin>>stairs[i];
    }

    memset(dp,-1,sizeof(dp));

    int ans = frogJump(stairs,n-1);

    cout<<"Minimum Energy : "<<ans<<endl;
return 0;
}