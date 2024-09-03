#include<iostream>
#include<vector>
using namespace std;

vector<vector<string> > dp(1001,vector<string>(1001,""));

string printLcs(string x,string y,int n,int m){
    if(n==0 || m==0){
        return "";
    }
    if(dp[n][m]!=""){
        return dp[n][m];
    }
    if(x[n-1]==y[m-1]){
        dp[n][m]=printLcs(x,y,n-1,m-1) + x[n-1];
    }
    else{
        string first = printLcs(x,y,n-1,m);
        string second = printLcs(x,y,n,m-1);
        if(first.length()>second.length()){
            dp[n][m]= first;
        }
        else{
            dp[n][m]= second;
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

    int n=x.length();
    int m=y.length();

    string ans=printLcs(x,y,n,m);

    cout<<"The longest common subsequence will be : "<<ans<<endl;
return 0;
}