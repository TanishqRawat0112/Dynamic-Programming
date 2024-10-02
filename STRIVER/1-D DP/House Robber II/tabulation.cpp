#include<iostream>
#include<vector>
using namespace std;

int houseRobber(vector<int>&houses,int start,int end){
    vector<int>dp(end-start + 1,0);
    dp[1]=houses[start];
    for(int i=2;i<=end-start;i++){
        dp[i] = max(dp[i-2] +  houses[start + i - 1], dp[i-1]);
    }
    return dp[end-start];
}

int houseRobber(vector<int>&houses,int start,int end){
    int prev2=0;
    int prev=houses[start];
    for(int i=2;i<=end-start;i++){
        int curr = max(prev2 + houses[start + i -1],prev);
        prev2=prev;
        prev=curr;
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

    int ans = max(houseRobber(houses,0,n-1),houseRobber(houses,1,n));

    cout<<"The maximum money that can be stolen is : "<<ans<<endl;
return 0;
}