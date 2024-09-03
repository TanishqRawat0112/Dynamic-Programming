#include<iostream>
using namespace std;

int countCoins(int coins[],int n,int sum){
    if(sum==0)return 0;
    if(n==0)return INT_MAX;
    if(coins[n-1]<=sum){
        return min(1+countCoins(coins,n,sum-coins[n-1]),countCoins(coins,n-1,sum));
    }
    else{
        return countCoins(coins,n-1,sum);
    }
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

    int ans=countCoins(coins,n,sum);
    if(ans==INT_MIN){
        ans=-1;
    }

    cout<<"The minimum number of coins to get the sum will be : "<<ans<<endl;
return 0;
}