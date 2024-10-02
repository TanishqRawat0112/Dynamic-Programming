#include<iostream>
#include<vector>
using namespace std;

int minCost(vector<int>&arr,int index){
    if(index==0 || index==1){
        return arr[index];
    }
    if(index==arr.size()){
        return min(minCost(arr,index-1),minCost(arr,index-2));
    }
    else{
        return arr[index] + min(minCost(arr,index-1),minCost(arr,index-2));
    }
}
 
int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    vector<int>arr(n);
    cout<<"Enter the array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ans=minCost(arr,n);

    cout<<"The minimum cost to reach the last stair is : "<<ans<<endl;
return 0;
}