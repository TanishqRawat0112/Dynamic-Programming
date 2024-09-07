#include<iostream>
#include<vector>
using namespace std;

int minDeletions(string x,string y,int n,int m,vector<vector<int> >&dp){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1 + dp[i-1][j-1];
            }
            else{
                dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
 
int main(){
    string x;
    cout<<"Enter the string here : ";
    cin>>x;

    string y = x;
    reverse(x.begin(),x.end());

    int n=x.length();
    vector<vector<int> >dp(n+1,vector<int>(n+1,0));

    int ans = n - minDeletions(x,y,n,n,dp);

    cout<<"The minimum number of deletions in String to make it a palindrome will be : "<<ans<<endl;

return 0;
}