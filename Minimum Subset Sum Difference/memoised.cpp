#include<iostream>
#include<vector>
using namespace std;

int static dp[100][1000];

int min_subset_diff(vector<int>&array,int n,int sum,int sumLeft){
    if(n==0){
        return abs(sum-sumLeft);
    }
    if(dp[n][sum]!=-1)return dp[n][sum];
    
    dp[n][sum]=min(min_subset_diff(array,n-1,sum-array[n-1],sumLeft+array[n-1]),min_subset_diff(array,n-1,sum,sumLeft));

    return dp[n][sum];
}
 
int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    vector<int>array(n);
    int sum=0;
    cout<<"Enter the array : "<<endl;
    for(int i=0;i<n;i++){
        cin>>array[i];
        sum+=array[i];
    }

    memset(dp,-1,sizeof(dp));

    int ans=min_subset_diff(array,n,sum,0);

    cout<<"The minimum Subset sum difference is : "<<ans<<endl;


return 0;
}