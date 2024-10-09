#include<iostream>
#include<vector>
using namespace std;

int numWays(vector<vector<int> >obstacles,int row,int col){
    vector<vector<int> >dp(row+1,vector<int>(col+1,0));

    if(obstacles[0][0]==0){
        dp[1][1]=1;
    }
    else{
        return 0;
    }
    
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            if((i==1 && j==1) || obstacles[i-1][j-1]==1)continue;
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[row][col];
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

    int ans  = numWays(obstacles , n , m );

    cout<<"The maximum number of ways will be : "<<ans<<endl;
return 0;
}