#include<iostream>
using namespace std;

int static dp[100][1000];

int countCoins(int coins[],int n,int sum){
    for(int i=0;i<=sum;i++){
        dp[0][i]=INT_MAX-1;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(coins[i-1]<=j){
                dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
 
int main(){
    int n;
    cout<<"Enter the size of the coins array : ";
    cin>>n;

    int coins[n];
    cout<<"Enter the coins array : "<<endl;
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }

    int sum;
    cout<<"Enter the sum : ";
    cin>>sum;

    memset(dp,0,sizeof(dp));

    int ans=countCoins(coins,n,sum);
    if(ans==INT_MAX-1){
        ans=-1;
    }

    cout<<"The minimum number of coins to get the sum will be : "<<ans<<endl;
return 0;
}