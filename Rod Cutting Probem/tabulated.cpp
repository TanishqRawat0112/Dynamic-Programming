#include<iostream>
using namespace std;

int static dp[102][1002];

int rod_cutting(int arr[],int price[],int n,int len){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=len;j++){
            if(arr[i-1]<=j){
                dp[i][j]=max(price[i-1]+dp[i][j-arr[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[n][len];
}
 
int main(){
    int n;
    cout<<"Enter the length of the rod : ";
    cin>>n;

    int arr[n];
    cout<<"Enter the array of lengths of the rod : "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int price[n];
    cout<<"Enter the price of the items according to the length : "<<endl;
    for(int i=0;i<n;i++){
        cin>>price[i];
    }

    memset(dp,0,sizeof(dp));

    int ans=rod_cutting(arr,price,n,n);

    cout<<"The maximum profit that can be generated will be : "<<ans<<endl;


return 0;
}