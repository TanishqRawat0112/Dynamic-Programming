#include<iostream>
using namespace std;

int numWays(int row,int col,vector<vector<int> >&dp){
    if(0 == row && 0 == col){
        return 1;
    }
    if(0>row || 0>col){
        return 0;
    }
    if(dp[row][col]!=-1)return dp[row][col];

    return dp[row][col]=numWays(row - 1,col,dp) + numWays(row,col - 1,dp);
}
 
int main(){
    int n;
    cout<<"Enter the number of rows of matrix : ";
    cin>>n;

    int m;
    cout<<"Enter the number of columns of matrix : ";
    cin>>m;

    vector<vector<int> >dp(n+1,vector<int>(m+1,-1));

    int ans = numWays(n-1,m-1,dp);

    cout<<"The maximum number of unique ways are : "<<ans<<endl;
return 0;
}