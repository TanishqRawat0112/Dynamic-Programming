#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<string,int>mpp;

bool scrambled(string a,string b){
    if(a.compare(b) == 0){
        return true;
    }
    if(a.length()<=1){
        return false;
    }
    string key = a + " " + b;
    if(mpp.find(key)!=mpp.end())return mpp[key];
    int n=a.length();
    for(int k=1;k<n;k++){
        bool cond1 = (
            scrambled(a.substr(0,k),b.substr(n-k,k))==true
            &&
            scrambled(a.substr(k,n-k),b.substr(0,n-k))==true
            );
        bool cond2 = (
            scrambled(a.substr(0,k),b.substr(0,k))==true
            &&
            scrambled(a.substr(k,n-k),b.substr(k,n-k))==true
        );
        if((cond1||cond2)==true)return mpp[key]=true;
    }
    return mpp[key] = false;
}
 
int main(){
    string a,b;
    cout<<"Enter the first string : ";
    cin>>a;

    cout<<"Enter the second string : ";
    cin>>b;

    int n = a.length();
    int m = b.length();
    if(n!=m){
        cout<<"They are not scrambled."<<endl;
        return 0;
    }
    if(n==0 && m==0){
        cout<<"They are scrambled."<<endl;
        return 0;
    }

    mpp.clear();

    bool ans = scrambled(a,b);
    if(ans){
        cout<<"They are scrambled."<<endl;
    }
    else{
        cout<<"They are not scrambled."<<endl;
    }
return 0;
}