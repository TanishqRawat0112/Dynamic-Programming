#include<iostream>
#include<vector>
using namespace std;

int min_subset_sum_diff(vector<int>&arr,int n,int range,int sum){
    vector<vector<bool> >dp(n+1,vector<bool>(range+1,false));
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=range;j++){
            if(arr[i-1]<=j){
                dp[i][j]=(dp[i-1][j] || dp[i-1][j-arr[i-1]]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    for(int j=range;j>=0;j--){
        if(dp[n][j]==true){
            return abs(sum-(2*j));
        }
    }
    return 0;
}

int min_diff(vector<int>&arr,int n){
    int sum=0;
    for(auto it:arr){
        sum+=it;
    }
    return min_subset_sum_diff(arr,n,(sum+1)/2,sum);
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

    int ans=min_diff(arr,n);

    cout<<"The minimum subset sum difference will be : "<<ans<<endl;
return 0;
}