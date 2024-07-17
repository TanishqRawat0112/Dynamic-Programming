#include<iostream>
#include<vector>
using namespace std;

bool static dp[102][1002];

bool isPresent(vector<int>&arr,int target,int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++){
            if(i==0 && j==0){
                dp[i][j]=true;
            }
            else if(i==0 || j==0){
                dp[i][j]=false;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(arr[i-1]<=target){
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
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
        memset(dp,false,sizeof(dp));
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