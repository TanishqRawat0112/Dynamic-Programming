#include<iostream>
using namespace std;

static int dp[101][1001];

int lps(string x , string y , int n, int m){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
 
int main(){
    string x,y;
    cout<<"Enter the string : ";
    cin>>x;

    y=x;
    reverse(x.begin(),x.end());

    int n=x.size();
    int m = y.size();

    memset(dp,0,sizeof(dp));

    int ans =  lps(x,y,n,m);

    cout<<"The length of the longest palindromic Subsequence will be : "<<ans<<endl;

return 0;
}