#include<iostream>
#include<vector>
using namespace std;

int mcm(vector<int>&arr,int n){
    vector<vector<int> >dp(n+1,vector<int>(n+1,0));
    for(int i=n-1;i>0;i--){
        for(int j=i+1;j<n;j++){
            int ans = INT_MAX;
            for(int k=i;k<j;k++){
                int tempAns = dp[i][k] + dp[k+1][j] + (arr[i-1]*arr[k]*arr[j]);
                ans=min(ans,tempAns);
            }
            dp[i][j] = ans;
        }
    }
    return dp[1][n-1];
}

 
int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    cout<<"Enter the array : "<<endl;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ans = mcm(arr,n);

    cout<<"The minimum answer from the matrix chain multiplication will be : "<<ans<<endl;
return 0;
}