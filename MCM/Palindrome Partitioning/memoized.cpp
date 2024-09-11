#include<iostream>
using namespace std;

static int dp[2001][2001];
static int pl[2001][2001];

bool isPalindrome(string x,int i,int j){
    if(i>=j)return true;
    if(pl[i][j]!=-1)return pl[i][j];   
    if(i<j){
        if(x[i]!=x[j])return pl[i][j] = false;
        return pl[i][j] = isPalindrome(x,i+1,j-1);
    }
    return false;
}

int minPart(string x,int i,int j){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if(isPalindrome(x,i,j)){
        return 0;
    }
    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        int tempAns = 1 + minPart(x,i,k) + minPart(x,k+1,j);
        ans=min(ans,tempAns);
    }
    return dp[i][j]=ans;
}
 
int main(){
    string x;
    cout<<"Enter the string : ";
    cin>>x;

    int n = x.size();
    memset(dp,-1,sizeof(dp));
    memset(pl,-1,sizeof(pl));

    int ans=minPart(x,0,n-1);

    cout<<"The Minimum Number of Partitions will be : "<<ans<<endl;

return 0;
}