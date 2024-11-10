#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector<int>&weight,vector<int>&price,int n,int wt){
    vector<int>dp(wt+1,0);
    vector<int>curr(wt+1,0);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=wt;j++){
            if(weight[i-1]<=j){
                curr[j] = max(price[i-1]+dp[j-weight[i-1]],dp[j]);
            }
            else{
                curr[j] = dp[j];
            }
        }
        dp=curr;
    }

    return dp[wt];
}
int knapsack2(vector<int>&weight,vector<int>&price,int n,int wt){
    vector<int>dp(wt+1,0);
    for(int i=1;i<=n;i++){
        for(int j=wt;j>=1;j--){
            if(weight[i-1]<=j){
                dp[j] = max(price[i-1]+dp[j-weight[i-1]],dp[j]);
            }
        }
    }

    return dp[wt];
}
 
int main(){
    int n;
    cout<<"Enter the number of items available : ";
    cin>>n;

    vector<int>weight(n);
    vector<int>price(n);
    cout<<"Enter the weight and price of each item : "<<endl;
    for(int i=0;i<n;i++){
        cin>>weight[i];
        cin>>price[i];
    }

    int wt;
    cout<<"Enter the maximum allowed weight in the bag : ";
    cin>>wt;

    int ans = knapsack2(weight,price,n,wt);

    cout<<"The maximum profit that can be achieved is : "<<ans<<endl;
return 0;
}