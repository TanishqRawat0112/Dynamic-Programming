#include<iostream>
#include<vector>
using namespace std;

int houseRobber(vector<int>&houses,int start,int end,vector<int>&dp){
    if(end == start)return houses[start];
    if(end<start)return 0;
    if(dp[end]!=-1)return dp[end];

    return dp[end]=max(houses[end] + houseRobber(houses,start,end-2,dp), houseRobber(houses,start,end-1,dp));
}
 
int main(){
    int n;
    cout<<"Enter the number of houses : ";
    cin>>n;

    vector<int>houses(n);
    cout<<"Enter the money stashed in each house : ";
    for(int i=0;i<n;i++){
        cin>>houses[i];
    }

    vector<int>dp(n,-1);
    int startInd = houseRobber(houses,0,n-2,dp);
    vector<int>dp2(n,-1);
    dp = dp2;
    int endInd = houseRobber(houses,1,n-1,dp);

    int ans = max(startInd,endInd);

    cout<<"The maximum money that can be stolen is : "<<ans<<endl;

return 0;
}