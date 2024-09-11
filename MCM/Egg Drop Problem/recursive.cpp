#include<iostream>
using namespace std;

static int dp[101][10001];

int minWays(int e,int f){
    if(f==0 || f==1 || e==1)return f;
    if(e==0)return 0;

    if(dp[e][f]!=-1)return dp[e][f];

    int ans=INT_MAX;

    for(int k=1;k<=f;k++){
        int temp = 1 + max(minWays(e-1,k-1),minWays(e,f-k));
        ans=min(ans,temp);
    }
    return dp[e][f] = ans;
}

int main(){
    int e,f;
    cout<<"Enter the number of eggs : ";
    cin>>e;

    cout<<"Enter the floors : ";
    cin>>f;

    memset(dp,-1,sizeof(dp));

    int ans = minWays(e,f);

    cout<<"The Minimum number of attempts to get the threshold floor will be : "<<ans<<endl;

return 0;
}