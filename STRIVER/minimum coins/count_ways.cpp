#include<iostream>
#include<vector>
using namespace std;

int minCoins(vector<int>&coins,int n,int target){
    vector<int>dp(target+1,0);
    dp[0]=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(coins[i-1]<=j){
                dp[j] = dp[j-coins[i-1]]+dp[j];
            }
        }
    }
    return dp[target];
}

int main(){
    int n;
    cout<<"Enter the number of coins : ";
    cin>>n;

    vector<int>coins(n);
    cout<<"Enter the value of each coin : "<<endl;
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }

    int target;
    cout<<"Enter the target : ";
    cin>>target;

    int ans = minCoins(coins,n,target);

    cout<<"The minimum coins for the target will be : "<<ans<<endl;

return 0;
}