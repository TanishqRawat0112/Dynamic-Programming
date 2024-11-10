#include<iostream>
using namespace std;

int lcs(string x,string y){
    int n = x.length();
    int m = y.length();
    vector<int>dp(m+1,0);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){
                dp[j]=1+ dp[j-1];
            }
            else{
                dp[j]=max(dp[j-1],dp[j]);
            }
        }
    }
    return dp[m];

} 
 
int main(){
    string x,y;
    cout<<"Enter the first string : ";
    cin>>x;

    cout<<"Enter the second string : ";
    cin>>y;

    int ans = lcs(x,y);

    cout<<"The length of the Longest Common Subsequence will be : "<<ans<<endl;
return 0;
}