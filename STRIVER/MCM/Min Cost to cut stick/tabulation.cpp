#include<iostream>
#include<vector>
using namespace std;

int minCost(vector<int>&cuts){
    int n = cuts.size()-2;
    vector<vector<int> >dp(n+2,vector<int>(n+2,0));
    for(int i=n;i>0;i--){
        for(int j=i;j<=n;j++){
            int ans = INT_MAX;
            for(int k=i;k<=j;k++){
                int tempAns = dp[i][k-1] + dp[k+1][j] + (cuts[j+1]-cuts[i-1]);
                ans=min(ans,tempAns);
            }
            dp[i][j]=ans;
        }
    }
    return dp[1][n];
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

    int ans = minCost(cuts);

    cout<<"The minimum cost to cut the stick is : "<<ans<<endl;

return 0;
}