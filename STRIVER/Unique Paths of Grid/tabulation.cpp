#include<iostream>
using namespace std;

int numWays(int row,int col){
    //Initialisation of starting row and column : 
    vector<vector<int> >dp(row+1,vector<int>(col+1,0));

    //Initialisation of (1,1)
    dp[1][1]=1;

    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            if( i==1 && j==1 )continue;
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

    int ans = numWays(n,m);

    cout<<"The maximum number of unique ways are : "<<ans<<endl;
return 0;
}