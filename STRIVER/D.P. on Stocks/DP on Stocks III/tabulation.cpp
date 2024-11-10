#include<iostream>
#include<vector>
using namespace std;

int highProfit(vector<int>&stocks){
    int n = stocks.size();
    vector<vector<vector<int> > >dp(n+1,vector<vector<int> >(2,vector<int>(3,0)));
    for(int i = n-1;i>=0;i--){
        for(int j=1;j>=0;j--){
            for(int k=1;k<3;k++){
                if(j==1){
                    dp[i][j][k] = max(dp[i+1][j][k],dp[i+1][0][k]-stocks[i]);
                }
                else{
                    dp[i][j][k] = max(dp[i+1][j][k],dp[i+1][1][k-1]+stocks[i]);
                }
            }
        }
    }
    return dp[0][1][2];
}
 
int main(){
    int n;
    cout<<"Enter the number of days : ";
    cin>>n;

    vector<int>stocks(n);
    cout<<"Enter the price of stock each day : "<<endl;
    for(int i=0;i<n;i++){
        cin>>stocks[i];
    }

    int ans = highProfit(stocks);

    cout<<"The maximum profit will be : "<<ans<<endl;
return 0;
}