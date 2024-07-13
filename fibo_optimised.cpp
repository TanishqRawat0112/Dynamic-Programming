#include<iostream>
using namespace std;

int fibonacci(int n){
    int prev2=0,prev=1;
    for(int i=2;i<=n;i++){
        int curr=prev2+prev;
        prev2=prev;
        prev=curr;
    }
    return prev;
}
 
int main(){
    int n;
    cout<<"Enter the position of the required Fibonacci number : ";
    cin>>n;

    int ans=fibonacci(n);

    cout<<"The "<<n<<"th fibonacci number is : "<<ans<<endl;
return 0;
}