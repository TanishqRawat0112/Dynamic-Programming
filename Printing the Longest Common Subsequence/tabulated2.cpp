#include<iostream>
#include<vector>
using namespace std;

int static dp[100][1000];

string printLcs(string x,string y,int n,int m){
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    int row =n;
    int col=m;
    string finalAns="";
    while(row!=0 && col!=0){
        if(x[row-1]==y[col-1]){
            finalAns+=x[row-1];
            row--;
            col--;
        }
        else{
            if(dp[row-1][col]>dp[row][col-1]){
                row--;
            }
            else{
                col--;
            }
        }
    }
    reverse(finalAns.begin(),finalAns.end());
    return finalAns;
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

    string ans=printLcs(x,y,n,m);

    cout<<"The longest common subsequence will be : "<<ans<<endl;
return 0;
}