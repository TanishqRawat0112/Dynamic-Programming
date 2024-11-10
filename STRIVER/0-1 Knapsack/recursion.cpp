#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector<int>&weight,vector<int>&price,int n,int wt){
    if(wt==0 || n==0){
        return 0;
    }

    if(weight[n-1]<=wt){
        return  max(price[n-1] + knapsack(weight,price,n-1,wt-weight[n-1]),knapsack(weight,price,n-1,wt));
    }
    else{
        return knapsack(weight,price,n-1,wt);
    }
}
 
int main(){
    int n;
    cout<<"Enter the number of items available : ";
    cin>>n;

    vector<int>weight(n);
    vector<int>price(n);
    cout<<"Enter the weight and price of each item : "<<endl;
    for(int i=0;i<n;i++){
        cin>>weight[i];
        cin>>price[i];
    }

    int wt;
    cout<<"Enter the maximum allowed weight in the bag : ";
    cin>>wt;

    int ans = knapsack(weight,price,n,wt);

    cout<<"The maximum profit that can be achieved is : "<<ans<<endl;
return 0;
}