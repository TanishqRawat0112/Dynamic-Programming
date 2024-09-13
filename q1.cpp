#include<iostream>
#include<unordered_map>
using namespace std;

bool isPermutation(string s1,string s2){
    unordered_map<char,int>mpp;
    for(auto it:s2){
            mpp[it]++;
        }

    for(auto it:s1){
            if(mpp.find(it)==mpp.end()){
                return false;
            }
        }
        return true;
}
 
int main(){
    string s1,s2;
    cin>>s1>>s2;

    bool ans = isPermutation(s1,s2);
    cout<<ans<<endl;
return 0;
}