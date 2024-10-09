#include<iostream>
using namespace std;

int minPathSum(vector<vector<int> >&grid,int row,int col){
    if(row==0 && col==0){
        return grid[0][0];
    }

    if(row<0 || col<0 || col>grid[row].size()){
        return INT_MAX;
    }

    return grid[row][col] + min(minPathSum(grid,row-1,col) , minPathSum(grid,row-1,col-1));
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

    int ans = INT_MAX;
    
    for(int i=0;i<n;i++){
        ans = min(ans,minPathSum(grid,n-1,i));
    }

    cout<<"The minimum path sum will be : "<<ans<<endl;
    
return 0;
}