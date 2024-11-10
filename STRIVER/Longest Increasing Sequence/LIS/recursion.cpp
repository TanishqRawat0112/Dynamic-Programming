#include<iostream>
#include<vector>
using namespace std;

// int lis(vector<int>&arr,int prev,int curr,vector<vector<int> >&dp){
//     if(curr==-1){
//         return 0;
//     }

//     if(dp[prev][curr]!=-1)return dp[prev][curr];

//     if(prev==arr.size() || arr[curr]<arr[prev]){
//         return dp[prev][curr] = max(1+lis(arr,curr,curr-1,dp),lis(arr,prev,curr-1,dp));
//     }
//     else{
//         return dp[prev][curr] = lis(arr,prev,curr-1,dp);
//     }
// }

int lis2(vector<int>&arr,int n,int index,int prev,vector<vector<int> >&dp){
    if(index>=n)return 0;
    if(dp[index][prev]!=-1)return dp[index][prev];

    if(prev==0 || arr[index]>arr[prev]){
        return dp[index][prev] = max(lis2(arr,n,index+1,prev,dp),1+lis2(arr,n,index+1,index,dp));
    }
    else{
        return dp[index][prev] = lis2(arr,n,index+1,prev,dp);
    }
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

    vector<vector<int> >dp(n+1,vector<int>(n+1,-1));

    int ans = lis2(arr,n,1,0,dp);

    cout<<"The length of the Longest Increasing Sequence is : "<<ans<<endl;


return 0;
}