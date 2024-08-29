#include<iostream>
using namespace std;

int static dp[102][1002];

int rod_cutting(int arr[],int price[],int n,int len){
    if(n==0||len==0)return 0;
    if(dp[n-1][len]!=-1)return dp[n][len];
    if(arr[n]<=len){
        return dp[n-1][len]=max(price[n-1] + rod_cutting(arr,price,n,len-arr[n-1]),rod_cutting(arr,price,n-1,len));
    }
    else{
        return dp[n-1][len]=rod_cutting(arr,price,n-1,len);
    }
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

    memset(dp,-1,sizeof(dp));

    int ans=rod_cutting(arr,price,n,n);

    cout<<"The maximum profit that can be generated will be : "<<ans<<endl;
return 0;
}