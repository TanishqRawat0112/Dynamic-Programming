#include<iostream>
#include<vector>
using namespace std;

int lis2(vector<int>&arr,int n){
    vector<int>dp(n,1),count(n,1);
    int ans = 0;
    for(int i = 0; i<n; i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] && 1+dp[j]>dp[i]){
                dp[i] = 1 + dp[j];
                count[i] = count[j];
            }
            else if(arr[j]<arr[i] && 1+dp[j]==dp[i]){
                count[i]+=count[j];
            }
        }
        if(ans<dp[i]){
            ans= dp[i];
        }
    }

    int countLis = 0;
    for(int i=0;i<n;i++){
        if(dp[i]==ans){
            countLis+=count[i];
        }
    }

    return countLis;
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

    cout<<"The number of Longest Increasing Sequence is : "<<ans<<endl;


return 0;
}