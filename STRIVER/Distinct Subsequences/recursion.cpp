#include<iostream>
#include<vector>
using namespace std;

int distinctSS(string x, string y,int n , int m,vector<vector<int> >&dp){
    if(m==-1){
        return 1;
    }
    else if(n<m){
        return 0;
    }

    if(dp[n][m]!=-1)return dp[n][m];

    if(x[n]==y[m]){
        return dp[n][m] = distinctSS(x,y,n-1,m-1,dp) + distinctSS(x,y,n-1,m,dp);
    }
    else{
        return dp[n][m] = distinctSS(x,y,n-1,m,dp);
    }
}
 
int main(){
    string x;
    string y;

    cout<<"Enter the first string : ";
    cin>>x;

    cout<<"Enter the second string : ";
    cin>>y;

    int n = x.length();
    int m = y.length();

    vector<vector<int> >dp(n,vector<int>(m,-1));

    int ans = distinctSS(x,y,n-1,m-1,dp);

    cout<<"The number of distinct subsequences will be : "<<ans<<endl;

return 0;
}