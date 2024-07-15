#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector<int>&weights,vector<int>&price,int cap,int item,int profit,int n){
    if(item==n)return profit;
    if(weights[item]>cap)return profit;
    else{
        int left=knapsack(weights,price,cap-weights[item],item+1,profit+price[item],n);
        int right=knapsack(weights,price,cap,item+1,profit,n);
        return max(left,right);
    }
}
 
int main(){
    int n;
    cout<<"Enter the number of items : ";
    cin>>n;

    vector<int>weights(n),price(n);
    cout<<"Enter the weight and price of the item : "<<endl;
    for(int i=0;i<n;i++){
        int wt,cost;
        cin>>wt>>cost;
        weights[i]=wt;
        price[i]=cost;
    }

    int cap;
    cout<<"Enter the capacity of the bag : ";
    cin>>cap;

    int ans=knapsack(weights,price,cap,0,0,n);

    cout<<"The maximum profit that can be generated will be : "<<ans<<endl;
return 0;
}