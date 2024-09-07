#include<iostream>
#include<vector>
using namespace std;

vector<vector<string> > dp(1001,vector<string>(1001,""));

string findScs(string x,string y,string lcs){
    int first=0,second=0,third=0;
    string ans="";
    while(first<x.size() && second<y.size() && third<lcs.size()){
        if(x[first]  == lcs[third] && y[second] == lcs[third]){
            ans+=x[first];
            first++;
            second++;
            third++;
        }
        else{
            if(x[first]==lcs[third]){
                ans+=y[second];
                second++;
            }
            else{
                ans+=x[first];
                first++;
            }
        }
    }
    while(first<x.size()){
        ans+=x[first];
        first++;
    }
    while(second<y.size()){
        ans+=y[second];
        second++;
    }
    return ans;
}

string printLcs(string x,string y,int n,int m){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=dp[i-1][j-1] + x[i-1];
            }
            else{
                if(dp[i-1][j].length()>dp[i][j-1].length()){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i][j-1];
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

    int n=x.length();
    int m=y.length();

    string ans=printLcs(x,y,n,m);

    string scs = findScs(x,y,ans);

    cout<<"The shortest common supersequence will be : "<<scs<<endl;
return 0;
}