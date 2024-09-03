#include<iostream>
#include<vector>
using namespace std;

int static dp[100][1000];

int count_subsets(vector<int>&arr,int n,int range){
    if(range==0){
        return 1;
    }
    if(n==0){
        return 0;
    }
    if(dp[n][range]!=-1)return dp[n][range];
    if(arr[n-1]<=range){
        return dp[n][range]=count_subsets(arr,n-1,range-arr[n-1])+count_subsets(arr,n-1,range);
    }
    else{
        return dp[n][range]=count_subsets(arr,n-1,range);
    }
}

 
int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    vector<int>arr(n);
    cout<<"Enter the array : "<<endl;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }

    int diff;
    cout<<"Enter the difference between the subsets : ";
    cin>>diff; 

    memset(dp,-1,sizeof(dp));

    if((sum+diff)%2==0){
        int range=(sum+diff)/2;
        int ans=count_subsets(arr,n,range);
        cout<<"The number of subsets will be : "<<ans<<endl;
    }
    else{
        cout<<"The number of subsets will be : 0"<<endl;
    }
return 0;
}