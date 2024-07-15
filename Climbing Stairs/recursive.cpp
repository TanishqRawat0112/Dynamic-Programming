#include<iostream>
using namespace std;

int climbing_stairs(int n){
    if(n<=1)return 1;
    return climbing_stairs(n-1) + climbing_stairs(n-2);
}
 
int main(){
    int n;
    cout<<"Enter the number of stairs : ";
    cin>>n;

    int ans=climbing_stairs(n);
    cout<<"The number of ways to climb the stairs will be : "<<ans<<endl;
return 0;
}