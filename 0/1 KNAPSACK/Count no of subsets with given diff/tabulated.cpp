#include<iostream>
#include<vector>
using namespace std;

int count_subsets(vector<int>&arr,int n,int range){
    vector<vector<int> >dp(n+1,vector<int>(range+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=range;j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][range];
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