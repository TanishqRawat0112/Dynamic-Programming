#include<iostream>
using namespace std;

static int dp[101][10001];

int minWays(int e,int f){
    if(f==0 || f==1 || e==1)return dp[e][f]=f;
    else if(dp[e][f]!=-1)return dp[e][f];

    else{
        int ans=INT_MAX;

        int left=1,right=f;
        while(left<=right){
            int mid = left + (right-left)/2;
            int leftCall = minWays(e-1,mid-1);
            int rightCall = minWays(e,f-mid);
            int temp = 1 + max(leftCall,rightCall);
            ans=min(ans,temp);
            if(leftCall<rightCall){
                left = mid + 1;
            }
            else{
                right = mid -1;
            }
        }
        dp[e][f] = ans;
    }
    return dp[e][f];
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