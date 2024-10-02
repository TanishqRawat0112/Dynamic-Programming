#include<iostream>
#include<vector>
using namespace std;

int houseRobber(vector<int>&houses,int n,vector<int>&dp){
    if(n==0){
        return houses[0];
    }
    if(n<0)return 0;
    if(dp[n]!=-1)return dp[n];

    return dp[n]=max(houses[n] + houseRobber(houses,n-2,dp),0 + houseRobber(houses,n-1,dp));
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

    int ans = houseRobber(houses,n-1,dp);

    cout<<"The maximum money that can be stolen is : "<<ans<<endl;

    
return 0;
}