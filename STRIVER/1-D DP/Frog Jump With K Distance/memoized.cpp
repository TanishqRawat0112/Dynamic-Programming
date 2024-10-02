#include<iostream>
#include<vector>
using namespace std;

int frogJump(vector<int>&stones,int n,int k,vector<int>&dp){
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];
    int minEnergy = INT_MAX/2;
    for(int i = 1;i<=k;i++){
        if((n-i)>=0){
            int energy = abs(stones[n]-stones[n-i]) + frogJump(stones,n-i,k,dp);
            minEnergy=min(minEnergy,energy);
        }
    }
    return dp[n] = minEnergy;
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

    vector<int>dp(n+1,-1);

    int ans = frogJump(stones,n-1,k,dp);

    cout<<"The minimum energy spent will be : "<<ans<<endl;
return 0;
}