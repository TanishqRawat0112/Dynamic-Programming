#include<iostream>
#include<vector>
using namespace std;

int static dp[102][1002];

bool isPresent(vector<int>&arr,int target,int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++){
            if(i==0){
                dp[i][j]=0;
            }
            if(j==0){
                dp[i][j]=1;
            }
        }
    }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=max(dp[i-1][j-arr[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][target];
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
    cout<<endl<<"The dp will be : "<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    if(ans){
        cout<<"Yes , the subset is present whose sum equals target."<<endl;
    }
    else{
        cout<<"No, there is no such subset present."<<endl;
    }
return 0;
}