#include<iostream>
#include<vector>
using namespace std;

int editDistance(string x,string y,int n,int m,vector<vector<int> >&dp){
    if(m==-1){
        return n+1;
    }
    if(n==-1)return m+1;

    if(dp[n][m]!=-1)return dp[n][m];

    if(x[n]==y[m]){
        return dp[n][m] = 0 + editDistance(x,y,n-1,m-1,dp);
    }
    else{
        return dp[n][m] = min(1+editDistance(x,y,n,m-1,dp),min(1+editDistance(x,y,n-1,m,dp),1+editDistance(x,y,n-1,m-1,dp)));
    }
}
 
int main(){
    string x,y;
    cout<<"Enter the first string : ";
    cin>>x;

    cout<<"Enter the second string : ";
    cin>>y;

    int n = x.length();
    int m = y.length();
    vector<vector<int> >dp(n,vector<int>(m,-1));

    int ans = editDistance(x,y,n-1,m-1,dp);

    cout<<"The minimum operations needed will be : "<<ans<<endl;
return 0;
}