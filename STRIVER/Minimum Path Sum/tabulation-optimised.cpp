#include<iostream>
using namespace std;
 
int minPathSum(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    vector<int>dp(col+1,200000);

    for(int i=1;i<=row;i++){
        vector<int>temp(col+1,200000);
        for(int j=1;j<=col;j++){
            if(i==1 && j==1){
                temp[j]=grid[0][0];
                continue;
            }
            temp[j] = grid[i-1][j-1] + min(dp[j],temp[j-1]);
        }
        dp=temp;
    }
    return dp[col];
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

    int ans = minPathSum(grid);

    cout<<"The minimum path sum possible will be : "<<ans<<endl;
return 0;
}