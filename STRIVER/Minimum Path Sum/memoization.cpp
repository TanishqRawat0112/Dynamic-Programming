#include<iostream>
#include<vector>
using namespace std;

int minPathSum(vector<vector<int> >&grid,int row,int col,vector<vector<int> >&dp){
    if(row == 0 && col == 0){
        return grid[row][col];
    }
    if(row<0 || col<0){
        return 1e9;
    }
    if(dp[row][col]!=-1)return dp[row][col];

    return dp[row][col] = grid[row][col] + min(minPathSum(grid,row-1,col,dp),minPathSum(grid,row,col-1,dp));
}
 
int main(){
    int n;
    cout<<"Enter the number of rows in matrix : ";
    cin>>n;

    int m;
    cout<<"Enter the number of columns in matrix : ";
    cin>>m;

    vector<vector<int> >grid(n,vector<int>(m,0));
    cout<<"Enter the grid : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    vector<vector<int> >dp(n,vector<int>(m,-1));

    int ans = minPathSum(grid,n-1,m-1,dp);

    cout<<"The minimum path sum possible will be : "<<ans<<endl;

return 0;
}