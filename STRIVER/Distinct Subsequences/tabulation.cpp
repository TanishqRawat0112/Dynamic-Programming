#include<iostream>
#include<vector>
using namespace std;

// int dss(string x, string y){
//     int n = x.length();
//     int m = y.length();
//     vector<vector<int> >dp(n+1,vector<int>(m+1,0));
//     for(int j=0;j<=n;j++)dp[j][0]=1;

//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             if(j>i)break;
//             if(x[i-1]==y[j-1]){
//                 dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
//             }
//             else{
//                 dp[i][j] = dp[i-1][j];
//             }
//         }
//     }
//     return dp[n][m];
// }

int dssOptimised(string x,string y){
    int n =x.length();
    int m = y.length();
    vector<int>dp(m+1,0),curr(m+1,0);

    for(int i=1;i<=n;i++){
        dp[0]=1;
        for(int j=1;j<=m;j++){
            if(j>i)break;
            if(x[i-1]==y[j-1]){
                curr[j] = dp[j] + dp[j-1];
            }
            else{
                curr[j] = dp[j];
            }
        }
        dp=curr;
    }
    return dp[m];
}
 
int main(){
    string x;
    string y;

    cout<<"Enter the first string : ";
    cin>>x;

    cout<<"Enter the second string : ";
    cin>>y;

    int n = x.length();
    int m = y.length();

    vector<vector<int> >dp(n,vector<int>(m,-1));

    int ans = dssOptimised(x,y);

    cout<<"The number of distinct subsequences will be : "<<ans<<endl;

return 0;
}