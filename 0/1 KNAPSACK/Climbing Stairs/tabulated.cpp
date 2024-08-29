#include<iostream>
#include<vector>
using namespace std;

int climbing_stairs(int n){
    vector<int>dp(n+1,-1);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];

}
 
int main(){
    int n;
    cout<<"Enter the number of stairs : ";
    cin>>n;

    int ans=climbing_stairs(n);
    cout<<"The number of ways to climb the stairs will be : "<<ans<<endl;   
return 0;
}