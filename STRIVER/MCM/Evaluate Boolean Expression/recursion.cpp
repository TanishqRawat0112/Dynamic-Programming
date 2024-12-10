#include<iostream>
using namespace std;

int evaluate2True(string &exp,int i,int j,bool isTrue,vector<vector<vector<int> > >&dp){
    if(i>j)return 0;
    if(i==j){
        if(isTrue){
            return exp[i]=='T';
        }
        else{
            return exp[i]=='F';
        }
    }

    if(dp[i][j][isTrue] != -1)return dp[i][j][isTrue];

    int ans = 0;
    for(int k=i+1;k<j;k+=2){
        int x1 = evaluate2True(exp,i,k-1,true,dp);
        int x2 = evaluate2True(exp,i,k-1,false,dp);
        int x3 = evaluate2True(exp,k+1,j,true,dp);
        int x4 = evaluate2True(exp,k+1,j,false,dp);
        if(exp[k]=='|'){
            if(isTrue){
                ans += ((x1*x4) + (x2*x3) + (x1*x3));
            }
            else{
                ans += (x2*x4);
            }
        }
        else if(exp[k]=='^'){
            if(isTrue){
                ans += ((x1*x4) + (x2*x3));
            }
            else{
                ans += ((x1*x3) + (x2*x4));
            }
        }
        else{
            if(isTrue){
                ans += (x1*x3);
            }
            else{
                ans += ((x1*x4) + (x2*x4) + (x2*x3));
            }
        }
    }
    return dp[i][j][isTrue] = ans;
}
 
int main(){
    string exp;
    cout<<"Enter the expression : ";
    cin>>exp;

    int n = exp.size();
    vector<vector<vector<int> > >dp(n+1,vector<vector<int> >(n+1,vector<int>(2,-1)));
    int ans = evaluate2True(exp,0,n-1,true,dp);

    cout<<"The number of expressions that will evaluate to true will be : "<<ans<<endl;
return 0;
}