#include<iostream>
using namespace std;

vector<int> printlis(vector<int>&arr,int n){
    vector<int>dp(n,1);
    vector<int>hash(n,0);
    for(int i=0;i<n;i++){
        hash[i]=i;
    }

    int ans = 0;
    int last_index = -1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] && 1+dp[j]>dp[i]){
                dp[i] = 1+dp[j];
                hash[i] = j;
            }
        }
        if(dp[i]>ans){
            ans = dp[i];
            last_index = i;
        }
    }

    vector<int>lis;
    while(last_index != hash[last_index]){
        lis.push_back(arr[last_index]);
        last_index = hash[last_index];
    }
    lis.push_back(arr[last_index]);
    reverse(lis.begin(),lis.end());
    return lis;
}
 
int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    vector<int>arr(n);
    cout<<"Enter the array : "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> ans = printlis(arr,n);

    cout<<"The Longest Increasing Sequence is : "<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
return 0;
}