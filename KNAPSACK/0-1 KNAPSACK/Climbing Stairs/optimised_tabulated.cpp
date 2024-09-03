#include<iostream>
using namespace std;

int climbing_stairs(int n){
    int prev2=1;
    int prev=1;
    for(int i=2;i<=n;i++){
        int curr=prev2+prev;
        prev2=prev;
        prev=curr;
    }
    return prev;
}
 
int main(){
    int n;
    cout<<"Enter the number of stairs : ";
    cin>>n;

    int ans=climbing_stairs(n);
    cout<<"The number of ways to climb the stairs will be : "<<ans<<endl; 
return 0;
}