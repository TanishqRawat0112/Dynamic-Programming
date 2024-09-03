#include<iostream>
using namespace std;

int static dp[101][1001];

int longestCommonSubstring(string x, string y, int n, int m) {
    int result=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            } 
            result=max(result,dp[i][j]);
        }
    }
    return result;
}
 
int main(){
    string x,y;
    cout<<"Enter the first string : ";
    cin>>x;

    cout<<"Enter the second string : ";
    cin>>y;

    int n=x.length();
    int m=y.length();
    memset(dp,0,sizeof(dp));
    int ans=longestCommonSubstring(x,y,n,m);

    cout<<"The length of the longest common subsequence will be : "<<ans<<endl;
return 0;
}