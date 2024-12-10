#include<iostream>
#include<vector>
using namespace std;

int burstBalloons(vector<int>&balloons){
    int n = balloons.size();
    balloons.push_back(1);
    balloons.insert(balloons.begin(),1);
    vector<vector<int> >dp(n+2,vector<int>(n+2,0));
    for(int i=n;i>0;i--){
        for(int j=i;j<=n;j++){
            int ans = INT_MIN;
            for(int k=i;k<=j;k++){
                int tempAns = dp[i][k-1] + dp[k+1][j] + (balloons[i-1]*balloons[k]*balloons[j+1]);
                ans=max(ans,tempAns);
            }
            dp[i][j] = ans;
        }
    }
    return dp[1][n];
}
 
int main(){
    int n;
    cout<<"Enter the number of balloons : ";
    cin>>n;

    vector<int>balloons(n);
    cout<<"Enter the points of balloons : "<<endl;
    for(int i=0;i<n;i++){
        cin>>balloons[i];
    }

    int ans = burstBalloons(balloons);
    cout<<"The maximum coins that can be achieved will be : "<<ans<<endl;
return 0;
}