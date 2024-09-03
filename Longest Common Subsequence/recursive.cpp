#include<iostream>
using namespace std;

int lcs(string x,string y,int n,int m){
    if(n==0 || m==0){
        return 0;
    }
    if(x[n-1]==y[m-1]){
        return 1 + lcs(x,y,n-1,m-1);
    }
    else{
        return max(lcs(x,y,n-1,m),lcs(x,y,n,m-1));
    }
}
 
int main(){
    string x,y;
    cout<<"Enter the first string : ";
    cin>>x;

    cout<<"Enter the second string : ";
    cin>>y;

    int n=x.length();
    int m=y.length();

    int ans=lcs(x,y,n,m);

    cout<<"The length of the longest common subsequence will be : "<<ans<<endl;
return 0;
}