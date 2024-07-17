#include<iostream>
#include<vector>
using namespace std;

int static dp[102][1002];

bool isPresent(vector<int>&arr,int target,int n){
    if(target==0)return true;
    if(n==0)return false;
    if(dp[n][target]!=-1)return dp[n][target];

    if(arr[n-1]<=target){
        if(dp[n][target]=isPresent(arr,target-arr[n-1],n-1)==true){
            return true;
        }
        if(dp[n][target]=isPresent(arr,target,n-1)==true){
            return true;
        }
    }
    else{
        if(dp[n][target]=isPresent(arr,target,n-1)==true){
            return true;
        }
    }
    return false;
}
 
int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    cout<<"Enter the array : ";
    vector<int>arr;
    for(int i=0;i<n;i++){
        int inp;
        cin>>inp;
        arr.push_back(inp);
    }

    int target;
    cout<<"Enter the target : ";
    cin>>target;

    memset(dp,-1,sizeof(dp));

    bool ans=isPresent(arr,target,n);

    if(ans){
        cout<<"Yes , the subset is present whose sum equals target."<<endl;
    }
    else{
        cout<<"No, there is no such subset present."<<endl;
    }
return 0;
}