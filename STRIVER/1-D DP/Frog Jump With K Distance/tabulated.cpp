#include<iostream>
#include<vector>
using namespace std;

int frogJump(vector<int>&stones,int n,int k,vector<int>&dp){
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int minEnergy = INT_MAX/2;
        for(int j=1;j<=k;j++){
            int energy = INT_MAX;
            if((i-j)>=0){
                energy = abs(stones[i]-stones[i-j]) + dp[i-j];
                minEnergy = min(minEnergy,energy);
            }
        }
        dp[i]=minEnergy;
    }
    return dp[n];
}
 
int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    vector<int>stones(n);
    cout<<"Enter the stones : ";
    for(int i=0;i<n;i++){
        cin>>stones[i];
    }

    int k;
    cout<<"Enter the maximum jump allowed : ";
    cin>>k;

    vector<int>dp(n+1,0);

    int ans = frogJump(stones,n-1,k,dp);

    cout<<"The minimum energy spent will be : "<<ans<<endl;
return 0;
}