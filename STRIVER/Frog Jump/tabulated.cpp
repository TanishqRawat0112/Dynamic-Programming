#include<iostream>
#include<vector>
using namespace std;

// static int dp[100001];

// int frogJump(vector<int>&stairs,int n){
//     dp[0]=0;
//     dp[1]=abs(stairs[1]-stairs[0]);
//     for(int i=2;i<=n;i++){
//         dp[i]=min(dp[i-1]+abs(stairs[i]-stairs[i-1]),dp[i-2]+abs(stairs[i]-stairs[i-2]));
//     }
//     return dp[n];
// }
int frogJump(vector<int>&stairs,int n){
    int first=0;
    int second=abs(stairs[1]-stairs[0]);
    for(int i=2;i<=n;i++){
        int third=min(second+abs(stairs[i]-stairs[i-1]),first+abs(stairs[i]-stairs[i-2]));
        first=second;
        second=third;
    }
    return second;
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

    // memset(dp,0,sizeof(dp));

    int ans = frogJump(stairs,n-1);

    cout<<"Minimum Energy : "<<ans<<endl;
return 0;
}