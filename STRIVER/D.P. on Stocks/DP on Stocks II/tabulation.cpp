#include<iostream>
#include<vector>
using namespace std;

int highProfit(vector<int>&stocks,int n){
    vector<vector<int> >dp(n+1,vector<int>(2,0));

    for(int i = n-1;i>=0;i--){
        for(int j = 1;j>=0;j--){
            if(j==1){
                dp[i][j] = max(0 + dp[i+1][j],dp[i+1][0]-stocks[i]);
            }
            else{
                dp[i][j] = max(0+dp[i+1][j],dp[i+1][1]+stocks[i]);
            }
        }
    }
    return dp[0][1];
}

int highProfit2(vector<int>&stocks){
    int n = stocks.size();
    vector<int>dp(2,0),curr(2,0);
    for(int i=n-1;i>=0;i--){
        for(int j=1;j>=0;j--){
            if(j==1){
                curr[j] = max(dp[j],dp[0]-stocks[i]);
            }
            else{
                curr[j] = max(dp[j],dp[1]+stocks[i]);
            }
        }
        dp=curr;
    }
    return dp[1];
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

    // vector<vector<int> >dp(n+1,vector<int>(2,-1));

    int ans = highProfit2(stocks);

    cout<<"The maximum profit will be : "<<ans<<endl;
return 0;
}