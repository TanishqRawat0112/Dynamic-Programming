#include<iostream>
using namespace std;

int minPathSum(vector<vector<int> >&grid,int row,int col,int totalRows){
    if(row==totalRows){
        return grid[row][col];
    }

    return grid[row][col] + min(minPathSum(grid,row+1,col,totalRows) , minPathSum(grid,row+1,col+1,totalRows));
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

    int ans = minPathSum(grid,0,0,n-1);

    cout<<"The minimum path sum will be : "<<ans<<endl;
    
return 0;
}