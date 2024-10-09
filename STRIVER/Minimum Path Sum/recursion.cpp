#include<iostream>
#include<vector>
using namespace std;

int minPathSum(vector<vector<int> >&grid,int row,int col){
    if(row == 0 && col == 0){
        return grid[row][col];
    }
    if(row<0 || col<0){
        return 1e9;
    }

    return grid[row][col] + min(minPathSum(grid,row-1,col),minPathSum(grid,row,col-1));
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

    int ans = minPathSum(grid,n-1,m-1);

    cout<<"The minimum path sum possible will be : "<<ans<<endl;

return 0;
}