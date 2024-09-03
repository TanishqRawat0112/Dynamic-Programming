#include<iostream>
using namespace std;

int unbounded(int wt[],int price[],int n,int cap){
    if(cap==0 || n==0){
        return 0;
    }
    if(wt[n-1]<=cap){
        return max(price[n-1]+unbounded(wt,price,n,cap-wt[n-1]),unbounded(wt,price,n-1,cap));
    }
    else{
        return unbounded(wt,price,n-1,cap);
    }
}
 
int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    int wt[n];
    int price[n];

    cout<<"Enter the weight of the items : "<<endl;
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }

    cout<<"Enter the price of the items : "<<endl;
    for(int i=0;i<n;i++){
        cin>>price[i];
    }

    int cap;
    cout<<"Enter the capacity of the bag : ";
    cin>>cap;

    int ans=unbounded(wt,price,n,cap);

    cout<<"The maximum profit that can be generated will be : "<<ans<<endl;
return 0;
}