#include<iostream>
#include<vector>
using namespace std;

bool wildcard(string x,string y){
    int n = x.length();
    int m = y.length();

    vector<vector<bool> >dp(n+1,vector<bool>(m+1,false));
    dp[0][0]=true;
    for(int j=1;j<=m;j++){
        if(y[j-1]=='*'){
            dp[0][j]=dp[0][j-1] || dp[0][j];
        }
        else{
            break;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1] || y[j-1]=='?'){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                if(y[j-1]=='*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }
    }
    return dp[n][m];
}

int main(){
    string x,y;
    cout<<"Enter the first string : ";
    cin>>x;

    cout<<"Enter the second string : ";
    cin>>y;

    int n = x.length();
    int m = y.length();

    vector<vector<int> >dp(n,vector<int>(m,-1));

    bool ans = wildcard(x,y);

    if(ans){
        cout<<"TRUE"<<endl;
    }
    else{
        cout<<"FALSE"<<endl;
    }

return 0;
}