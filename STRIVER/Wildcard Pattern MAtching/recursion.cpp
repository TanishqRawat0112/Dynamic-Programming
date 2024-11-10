#include<iostream>
#include<vector>
using namespace std;

bool wildcard(string x,string y,int n,int m,vector<vector<int> >&dp){
    if(n==-1 && m==-1)return true;
    if(n==-1){
        for(int i = 0;i<=m;i++){
            if(y[i]!='*')return false;
        }
        return true;
    }
    if(m==-1)return false;

    if(dp[n][m]!=-1)return dp[n][m];

    if(x[n]==y[m] || y[m]=='?')return dp[n][m]= wildcard(x,y,n-1,m-1,dp);
    else{
        if(y[m]=='*')return dp[n][m] = (wildcard(x,y,n-1,m,dp) || wildcard(x,y,n,m-1,dp));
    }
    return dp[n][m] = false;
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

    bool ans = wildcard(x,y,n-1,m-1,dp);

    if(ans){
        cout<<"TRUE"<<endl;
    }
    else{
        cout<<"FALSE"<<endl;
    }

return 0;
}