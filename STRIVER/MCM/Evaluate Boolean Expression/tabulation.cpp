#include<iostream>
using namespace std;

int mod = 10000000007;

int evaluate(string exp){
    int n = exp.length();
    vector<vector<vector<int> > >dp(n,vector<vector<int> >(n,vector<int>(2,0)));

    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(i==j){
                dp[i][j][0]=(exp[i]=='F');
                dp[i][j][1]=(exp[i]=='T');
            }
            else {
                int ways=0;
                for(int ind=i+1;ind<=j-1;ind+=2){
                    int lt=dp[i][ind-1][1]%mod;
                    int rt=dp[ind+1][j][1]%mod;
                    int lf=dp[i][ind-1][0]%mod;
                    int rf=dp[ind+1][j][0]%mod;
                    if(exp[ind]=='&'){
                        dp[i][j][0]=(dp[i][j][0]+(lt*rf+lf*rt+lf*rf))%mod;
                        dp[i][j][1]=(dp[i][j][1]+(lt*rt))%mod;
                    }
                    else if(exp[ind]=='|'){
                        dp[i][j][0]=(dp[i][j][0]+(lf*rf))%mod;
                        dp[i][j][1]=(dp[i][j][1]+(lt*rf+lf*rt+lt*rt))%mod;
                    }
                    else{
                        dp[i][j][0]=(dp[i][j][0]+(lt*rt+lf*rf))%mod;
                        dp[i][j][1]=(dp[i][j][1]+(lt*rf+lf*rt))%mod;
                    }
                }
            }
        }
    }
    return dp[0][n-1][1];
}


int main(){
    string exp;
    cout<<"Enter the expression : ";
    cin>>exp;

    int n = exp.size();
    int ans = evaluate(exp);

    cout<<"The number of expressions that will evaluate to true will be : "<<ans<<endl;
return 0;
}