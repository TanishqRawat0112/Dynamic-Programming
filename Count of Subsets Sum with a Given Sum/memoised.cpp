#include<iostream>
#include<vector>
using namespace std;

int static dp[100][1000];

int count_subsets(vector<int>array,int n,int sum){
    if(sum==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(dp[n][sum]!=-1)return dp[n][sum];
    if(array[n]<=sum){
        dp[n][sum]= count_subsets(array,n-1,sum-array[n])+count_subsets(array,n-1,sum);
    }
    else{
        dp[n][sum] = count_subsets(array,n-1,sum);
    }
    return dp[n][sum];
}
 
int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    vector<int>array(n);
    cout<<"Enter the array : ";
    for(int i=0;i<n;i++){
        cin>>array[i];
    }

    int sum;
    cout<<"Enter the Given Sum : ";
    cin>>sum;

    memset(dp,-1,sizeof(dp));

    int ans=count_subsets(array,n-1,sum);

    cout<<"The Number of Subsets with given sum will be : "<<ans<<endl;
return 0;
}