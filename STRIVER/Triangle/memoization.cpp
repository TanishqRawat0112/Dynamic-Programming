#include<iostream>
using namespace std;

int minPathSum(vector<vector<int> >&grid,int row,int col,vector<vector<int> >&dp){
    if(row==0 && col==0){
        return grid[0][0];
    }

    if(row<0 || col<0 || col>grid[row].size()){
        return INT_MAX;
    }

    if(dp[row][col]!=INT_MAX)return dp[row][col];

    return dp[row][col] = grid[row][col] + min(minPathSum(grid,row-1,col,dp) , minPathSum(grid,row-1,col-1,dp));
}

int minPathSum2(vector<vector<int> >&grid,int row,int col,int total,vector<vector<int> >&dp){
    if(row==total){
        return grid[row][col];
    }
    if(dp[row][col]!=-1)return dp[row][col];

    return dp[row][col] = grid[row][col] + min(minPathSum2(grid,row+1,col,total,dp),minPathSum2(grid,row+1,col+1,total,dp));
}

int main(){
    int n;
    cout<<"Enter the number of rows : ";
    cin>>n;

    vector<vector<int> >grid;
    cout<<"Enter the triangular grid : "<<endl;
    for(int i=0;i<n;i++){
        vector<int>row(i+1,0);
        for(int j=0;j<=i;j++){
            cin>>row[j];
        }
        grid.push_back(row);
    }
    vector<vector<int> >dp(n,vector<int>(n,-1));
    int ans = minPathSum2(grid,0,0,n-1,dp);

    cout<<"The minimum path sum will be : "<<ans<<endl;
    
return 0;
}