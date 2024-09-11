#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int numWays(int target){
    int mod = 1e9 + 7;
    if(target<=1)return pow(2,0);
    int ans = pow(2,target-1);
    ans%=mod;
    return ans;  
}
 
int main(){
    int target;
    cin>>target;
    int ans = numWays(target);
    cout<<ans;
return 0;
}