#include<iostream>
#include<vector>
using namespace std;

int minPathSum(vector<vector<int> >&grid,int row,int col){
    vector<vector<int> >dp(row+1,vector<int>(col+1,2000));

    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            if(i==1 && j==1){
                dp[i][j]=grid[0][0];
                continue;
            }
            dp[i][j] = grid[i-1][j-1] + min(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[row][col];
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

    int ans = minPathSum(grid,n,m);

    cout<<"The minimum path sum possible will be : "<<ans<<endl;

return 0;
}