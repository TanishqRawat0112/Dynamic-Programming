#include<iostream>
using namespace std;

int lis(vector<int>&arr,int n){
    vector<int>dp(n,1);
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                dp[i] = max(dp[i],1+dp[j]);
            }
        }
        ans=max(ans,dp[i]);
    }
    return ans;
}
 
int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    vector<int>arr(n);
    cout<<"Enter the array : "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ans = lis(arr,n);

    cout<<"The length of the Longest Increasing Sequence is : "<<ans<<endl;
return 0;
}