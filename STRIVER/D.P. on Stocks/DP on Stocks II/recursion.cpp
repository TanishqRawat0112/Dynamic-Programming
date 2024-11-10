#include<iostream>
#include<vector>
using namespace std;

int bestTime(vector<int>stocks,int index,bool buy,vector<vector<int> >&dp){
    if(index == stocks.size()-1){
        if(buy){
            return 0;
        }
        else{
            return stocks[index];
        }
    }

    if(dp[index][buy] != -1)return dp[index][buy];
    if(buy){
        return dp[index][buy] = max(0+bestTime(stocks,index+1,buy,dp),bestTime(stocks,index+1,!buy,dp)-stocks[index]);
    }
    else{
        return dp[index][buy] = max(0+bestTime(stocks,index+1,buy,dp),bestTime(stocks,index+1,!buy,dp)+stocks[index]);
    }
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

    vector<vector<int> >dp(n+1,vector<int>(2,-1));

    int ans = bestTime(stocks,0,true,dp);

    cout<<"The maximum profit will be : "<<ans<<endl;
return 0;
}