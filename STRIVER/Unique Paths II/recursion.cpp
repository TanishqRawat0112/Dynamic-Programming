#include<iostream>
#include<vector>
using namespace std;

int numWays(vector<vector<int> >obstacles,int row,int col){
    if(row == 0 && col ==0){
        return 1;
    }
    if(row<0 || col<0 || obstacles[row][col]==1){
        return 0;
    }

    return numWays(obstacles,row-1,col) + numWays(obstacles,row,col-1);
}
 
int main(){
    int n;
    cout<<"Enter the number of rows of matrix : ";
    cin>>n;

    int m;
    cout<<"Enter the number of columns of matrix : ";
    cin>>m;

    vector<vector<int> >obstacles(n,vector<int>(m,0));
    cout<<"Enter the obstacles grid : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>obstacles[i][j];
        }
    }

    int ans  = numWays(obstacles , n-1 , m-1);

    cout<<"The maximum number of ways will be : "<<ans<<endl;
return 0;
}