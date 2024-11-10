#include<iostream>
#include<vector>
using namespace std;

int bestTime(vector<int>stocks,int n){
    int buy = stocks[0];
    int profit = 0;
    for(int i=1;i<n;i++){
        if(stocks[i]<buy){
            buy = stocks[i];
        }
        else{
            profit = max(profit,stocks[i]-buy);
        }
    }

    return profit;
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

    int ans = max(0,bestTime(stocks,n-1));

    cout<<"The maximum profit will be : "<<ans<<endl;
return 0;
}