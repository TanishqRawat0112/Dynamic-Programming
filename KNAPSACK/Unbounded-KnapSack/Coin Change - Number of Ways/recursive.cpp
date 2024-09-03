#include<iostream>
using namespace std;

int countCoins(int coins[],int n,int sum){
    if(sum==0)return 1;
    if(n==0)return 0;
    if(coins[n-1]<=sum){
        return countCoins(coins,n,sum-coins[n-1])+countCoins(coins,n-1,sum);
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

    cout<<"The number of ways to get the sum will be : "<<ans<<endl;
return 0;
}