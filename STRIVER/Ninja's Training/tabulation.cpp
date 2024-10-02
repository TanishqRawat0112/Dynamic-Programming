#include<iostream>
#include<vector>
using namespace std;

int ninjaTraining(vector<vector<int> >&training,int n){
    vector<vector<int> >dp(n+1,vector<int>(4,0));
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            if(j==1){
                dp[i][j]=training[i-1][j-1] + max(dp[i-1][2],dp[i-1][3]);
            }
            if(j==2){
                dp[i][j] = training[i-1][j-1] + max(dp[i-1][1],dp[i-1][3]);
            }
            if(j==3){
                dp[i][j] = training[i-1][j-1] + max(dp[i-1][1],dp[i-1][2]);
            }
            ans = max(ans,dp[i][j]);
        }
    }
    return ans;
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

    int ans = ninjaTraining(training,n);

    cout<<"Maximum points that can be earned are : "<<ans<<endl;
return 0;
}