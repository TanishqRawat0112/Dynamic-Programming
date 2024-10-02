#include<iostream>
#include<vector>
using namespace std;

int houseRobber(vector<int>&nums,int n){
    vector<int>dp(n+1,0);
    dp[1]=nums[0];
    for(int i=2;i<=n;i++){
        dp[i] = max(nums[i-1] + dp[i-2],dp[i-1]);
    }
    return dp[n];
}

int houseRobber2(vector<int>&nums,int n){
    int prev2 = 0;
    int prev=nums[0];
    for(int i=2;i<=n;i++){
        int curr = max(nums[i-1] + prev2,prev);
        prev2 = prev;
        prev = curr;
    }
    return prev;
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

    int ans = houseRobber2(houses,n);

    cout<<"The maximum cash that can be stolen is : "<<ans<<endl;

return 0;
}