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

// int lis(vector<int>&arr){
//     int n = arr.size();
//     vector<vector<int> >dp(n+1,vector<int>(n+1,0));

//     for(int i=n-1;i>=0;i--){
//         for(int j=i-1;j>=-1;j--){
//             int len = dp[i+1][j+1];
//             if(j==-1 || arr[i]>arr[j]){
//                 len = max(len,dp[i+1][i+1]);
//             }
//             dp[i][j+1] = len;
//         }
//     }
//     return dp[0][0];
// }

// int lis2(vector<int>&arr,int n,int index,int prev,vector<vector<int> >&dp){
//     if(index>n)return 0;
//     if(dp[index][prev]!=-1)return dp[index][prev];

//     if(prev==0 || arr[index]>arr[prev]){
//         return dp[index][prev] = max(lis2(arr,n,index+1,prev,dp),1+lis2(arr,n,index+1,index,dp));
//     }
//     else{
//         return dp[index][prev] = lis2(arr,n,index+1,prev,dp);
//     }
// }

int lis2(vector<int>&arr,int n){
    vector<int>dp(n+2,0);
    vector<int>curr(n+2,0);
    for(int i=n;i>0;i--){
        for(int j=0;j<n+1;j++){
            if(j==0 || arr[i-1]>arr[j-1]){
                curr[j] = max(dp[j],1+dp[i]);
            }
            else{
                curr[j] = dp[j];
            }
        }
        dp=curr;
    }
    return dp[0];
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

    int ans = lis2(arr,n);

    cout<<"The length of the Longest Increasing Sequence is : "<<ans<<endl;


return 0;
}