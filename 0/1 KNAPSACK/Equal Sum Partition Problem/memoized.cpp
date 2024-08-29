#include<iostream>
#include<vector>
using namespace std;

int static dp[102][1002];

bool isPresent(vector<int>&arr,int target,int n){
    if(target==0)return true;
    if(n==0)return false;

    if(dp[n][target]!=-1)return dp[n][target];

    if(arr[n-1]<=target){
        if(dp[n][target]=isPresent(arr,target-arr[n-1],n-1)||isPresent(arr,target,n-1)){
            return true;
        }
    }
    else{
        if(dp[n][target]=isPresent(arr,target,n-1)){
            return true;
        }
    }
    return false;
}
 
int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    cout<<"Enter the array : "<<endl;
    int target=0;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int inp;
        cin>>inp;
        target+=inp;
        arr.push_back(inp);
    }
    bool ans;
    if(target&1){
        ans=false;
    }
    else{
        memset(dp,-1,sizeof(dp));
        ans=isPresent(arr,target/2,n);
    }

    if(ans){
        cout<<"Yes, the array can be divided into equal sum subsets."<<endl;
    }
    else{
        cout<<"No, the array can't be divided."<<endl;
    }

return 0;
}