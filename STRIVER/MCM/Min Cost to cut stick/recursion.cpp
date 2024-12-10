#include<iostream>
#include<vector>
using namespace std;

int minCost(vector<int>&cuts,int i,int j,vector<vector<int> >&dp){
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans = INT_MAX;
    for(int k=i;k<=j;k++){
        int tempAns = minCost(cuts,i,k-1,dp) + minCost(cuts,k+1,j,dp) + (cuts[j+1]-cuts[i-1]);
        ans=min(ans,tempAns);
    }
    return dp[i][j] = ans;
}
 
int main(){
    int len;
    cout<<"Enter the length of the stick : ";
    cin>>len;

    int n;
    cout<<"Enter the number of cuts : ";
    cin>>n;

    cout<<"Enter the cuts : "<<endl;
    vector<int>cuts(n+2);
    cuts[0]=0;
    for(int i=1;i<=n;i++){
        cin>>cuts[i];
    }
    cuts[n+1]=len;

    sort(cuts.begin(),cuts.end());
    vector<vector<int> >dp(len+1,vector<int>(len+1,-1));

    int ans = minCost(cuts,1,n,dp);

    cout<<"The minimum cost to cut the stick is : "<<ans<<endl;

return 0;
}