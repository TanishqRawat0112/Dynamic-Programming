#include<iostream>
#include<vector>
using namespace std;

int count_subsets(vector<int>&arr,int n,int sum){
    vector<vector<int> >dp(n+1,vector<int>(sum+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
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

    int sum;
    cout<<"Enter the required sum : ";
    cin>>sum;

    int ans=count_subsets(arr,n,sum);

    cout<<"The Number of subsets which will sum to "<<sum<<" will be : "<<endl;
    cout<<ans<<endl;
return 0;
}