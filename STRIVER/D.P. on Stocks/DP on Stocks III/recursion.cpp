#include<iostream>
#include<vector>
using namespace std;

int highProfit(vector<int>&stocks,int index,bool buy,int times,int n,vector<vector<vector<int> > >&dp){
    if(times==0)return 0;
    if(index == n)return 0;
    if(dp[index][buy][times]!=-1)return dp[index][buy][times];
    if(buy){
        return dp[index][buy][times] = max(0+highProfit(stocks,index+1,buy,times,n,dp),-stocks[index]+highProfit(stocks,index+1,!buy,times,n,dp));
    }
    else{
        return dp[index][buy][times] = max(0+highProfit(stocks,index+1,buy,times,n,dp),stocks[index]+highProfit(stocks,index+1,!buy,times-1,n,dp));
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

    vector<vector<vector<int> > >dp(n,vector<vector<int> >(2,vector<int>(3,-1)));
    int ans = highProfit(stocks,0,1,2,n,dp);

    cout<<"The maximum profit will be : "<<ans<<endl;
return 0;
}