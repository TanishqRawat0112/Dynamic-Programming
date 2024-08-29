#include<iostream>
using namespace std;

int rod_cutting(int arr[],int price[],int n,int len){
    if(n==0||len==0)return 0;
    if(arr[n-1]<=len){
        return max(price[n-1] + rod_cutting(arr,price,n,len-arr[n-1]),rod_cutting(arr,price,n-1,len));
    }
    else{
        return rod_cutting(arr,price,n-1,len);
    }
}
 
int main(){
    int n;
    cout<<"Enter the length of the rod : ";
    cin>>n;

    int arr[n];
    cout<<"Enter the array of lengths of the rod : "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int price[n];
    cout<<"Enter the price of the items according to the length : "<<endl;
    for(int i=0;i<n;i++){
        cin>>price[i];
    }

    int ans=rod_cutting(arr,price,n,n);

    cout<<"The maximum profit that can be generated will be : "<<ans<<endl;
return 0;
}