#include<iostream>
#include<vector>
using namespace std;

int rodCutting(vector<int>&price,int n){
    vector<int>dp(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i<=j){
                dp[j]=max(price[i-1] + dp[j-i],dp[j]);
            }
        }
    }
    return dp[n];
}
 
int main(){
    int n;
    cout<<"Enter the length of the rod : ";
    cin>>n;

    vector<int>price(n);
    cout<<"Enter the price associated with the length of the rod : "<<endl;
    for(int i=0;i<n;i++){
        cin>>price[i];
    }

    int ans = rodCutting(price,n);

    cout<<"The maximum proft that can be made out of the rod is : "<<ans<<endl;
return 0;
}