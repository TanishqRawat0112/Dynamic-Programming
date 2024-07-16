#include<iostream>
#include<vector>
using namespace std;

int static dp[102][1002];

int knapsack(vector<int>&weights,vector<int>&price,int cap,int n){
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=cap;i++){
        dp[0][i]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=cap;j++){
            if(weights[i-1]<=j){
                dp[i][j]=max(price[i-1]+ dp[i-1][j-weights[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][cap];
}

 
int main(){
    int n;
    cout<<"Enter the number of items : ";
    cin>>n;

    vector<int>weights(n),price(n);
    cout<<"Enter the weight and price of the item : "<<endl;
    for(int i=0;i<n;i++){
        int wt,cost;
        cin>>wt>>cost;
        weights[i]=wt;
        price[i]=cost;
    }

    int cap;
    cout<<"Enter the capacity of the bag : ";
    cin>>cap;

    memset(dp,-1,sizeof(dp));

    int ans=knapsack(weights,price,cap,n);

    cout<<"The maximum profit that can be generated will be : "<<ans<<endl;

    cout<<"Resultant dp will be : ";
    for(int i=0;i<=n;i++){
        for(int j=0;j<=cap;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}