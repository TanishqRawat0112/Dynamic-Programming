#include<iostream>
using namespace std;

int static dp[101][1001];

int longestCommonSubstring(string &s1, string &s2, int i, int j, int count) {
    if (i == 0 || j == 0) {
        return count;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = 1 + longestCommonSubstring(s1, s2, i - 1, j - 1, count);
        count=max(count,dp[i][j]);
    }
    else{
        dp[i][j]=0;
    }
    longestCommonSubstring(s1, s2, i - 1, j, count);
    longestCommonSubstring(s1, s2, i, j - 1, count);

    return dp[i][j];
}
 
int main(){
    string x,y;
    cout<<"Enter the first string : ";
    cin>>x;

    cout<<"Enter the second string : ";
    cin>>y;

    int n=x.length();
    int m=y.length();
    memset(dp,-1,sizeof(dp));
    int ans=longestCommonSubstring(x,y,n,m,0);

    cout<<"The length of the longest common subsequence will be : "<<ans<<endl;
return 0;
}