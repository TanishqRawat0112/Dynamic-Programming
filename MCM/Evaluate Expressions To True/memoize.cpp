#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<string,int>mp;

int ways2eval(string exp,int i,int j,bool isTrue){
    if(i>j)return false;
    if(i==j){
        if(isTrue)return exp[i]=='T';
        else return exp[i]=='F';
    }

    string eval = to_string(i) + " " + to_string(j) + " " + to_string(isTrue);

    if(mp.find(eval)!=mp.end())return mp[eval];
    
    int ans = 0;

    for(int k=i+1;k<j;k+=2){
        int lt=ways2eval(exp,i,k-1,true);
        int lf=ways2eval(exp,i,k-1,false);
        int rt=ways2eval(exp,k+1,j,true);
        int rf=ways2eval(exp,k+1,j,false);

        if(exp[k]=='|'){
            if(isTrue){
                ans += (lt*(rt+rf)) + (rt*(lt+lf)) - (rt*lt);
            }
            else{
                ans+=lf*rf;
            }
        }
        else if(exp[k]=='&'){
            if(isTrue){
                ans += lt*rt;
            }
            else{
                ans+= (lf*(rt+rf)) + (rf*(lt+lf)) - (rf*lf);
            }
        }
        else{
            if(isTrue){
                ans+= lt*rf + rt*lf;
            }
            else{
                ans+= lt*rt + lf*rf;
            }
        }
    }
    return mp[eval] = ans;
}
 
int main(){
    string exp;
    cout<<"Enter the expression : ";
    cin>>exp;
    int n = exp.length();
    mp.clear();

    int ans = ways2eval(exp,0,n-1,true);

    cout<<"The number of ways to get the expressions as TRUE are : "<<ans<<endl;
return 0;
}