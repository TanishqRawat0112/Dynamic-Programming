#include<iostream>
using namespace std;

int minPathSum(vector<vector<int> >&grid,int row){
    vector<vector<int> >dp(row+1,vector<int>(row+1,INT_MAX));
    for(int i=1;i<=row;i++){
        for(int j=1;j<=i;j++){
            if(i==1 && j==1){
                dp[i][j] = grid[0][0];
                continue;
            }
            dp[i][j] = grid[i-1][j-1] + min(dp[i-1][j],dp[i-1][j-1]);
        }
    }
    
    int ans = INT_MAX;
    for(int i=0;i<=row;i++){
        ans=min(ans,dp[row][i]);
    }
    return ans;
}

int minPathSum2(vector<vector<int> >&grid){
    int size = grid.size();
    vector<vector<int> >dp(size,vector<int>(size,0));
    for(int j=0;j<size;j++){
        dp[size-1][j] = grid[size-1][j];
    }

    for(int i=size-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            dp[i][j] = grid[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    return dp[0][0];   
}

int minPathSum3(vector<vector<int> >&grid){
    int n = grid.size();
    vector<int>dp(n,0);
    for(int j=0;j<n;j++){
        dp[j] = grid[n-1][j];
    }

    for(int i = n-2;i>=0;i--){
        vector<int>curr(n,0);
        for(int j=i;j>=0;j--){
            curr[j] = grid[i][j] + min(dp[j],dp[j+1]);
        }
        dp=curr;
    }
    return dp[0];
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

    int ans = minPathSum3(grid);
    cout<<"The minimum path sum will be : "<<ans<<endl;
    
return 0;
}