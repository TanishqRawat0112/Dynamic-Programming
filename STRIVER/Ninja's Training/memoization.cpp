#include<iostream>
#include<vector>
using namespace std;

int ninjaTraining(vector<vector<int> >&training,int n,int act,vector<vector<int> >&dp){
    if(n==0)return 0;
    if(dp[n-1][act]!=-1)return dp[n-1][act];
    int ans = 0;
    for(int i=0;i<3;i++){
        if(i!=act){
            ans = max(ans,ninjaTraining(training,n-1,i,dp) + training[n-1][i]);
        }
    }
    return dp[n-1][act]=ans;
}
 
int main(){
    int n;
    cout<<"Enter the number of days : ";
    cin>>n;

    vector<vector<int> >training(n,vector<int>(3,0));
    cout<<"Enter the training points for each day : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>training[i][j];
        }
    }

    vector<vector<int> >dp(n,vector<int>(4,-1));

    int ans = ninjaTraining(training,n,3,dp);

    cout<<"Maximum points that can be earned are : "<<ans<<endl;
return 0;
}