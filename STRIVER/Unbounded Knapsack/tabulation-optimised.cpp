#include<iostream>
#include<vector>
using namespace std;

int unbounded(vector<int>&weight,vector<int>&price,int n,int wt){
    vector<int>dp(wt+1,0);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=wt;j++){
            if(weight[i-1]<=j){
                dp[j]=max(price[i-1]+dp[j-weight[i-1]],dp[j]);
            }
        }
    }
    return dp[wt];
}
 
int main(){
    int n;
    cout<<"Enter the number of items : ";
    cin>>n;

    vector<int>weight(n),price(n);
    cout<<"Enter the weight and price of each item : "<<endl;
    for(int i=0;i<n;i++){
        cin>>weight[i];
        cin>>price[i];
    }

    int wt;
    cout<<"Enter the maximum weight allowed : ";
    cin>>wt;

    int ans = unbounded(weight,price,n,wt);

    cout<<"The maximum price that can be obtained will be : "<<ans<<endl;
return 0;
}