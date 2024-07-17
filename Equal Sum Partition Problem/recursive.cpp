#include<iostream>
#include<vector>
using namespace std;

bool isPresent(vector<int>&arr,int target,int n){
    if(target==0)return true;
    if(n==0)return false;

    if(arr[n-1]<=target){
        if(isPresent(arr,target-arr[n-1],n-1)){
            return true;
        }
        if(isPresent(arr,target,n-1)){
            return true;
        }
    }
    else{
        if(isPresent(arr,target,n-1)){
            return true;
        }
    }
    return false;
}
 
int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    cout<<"Enter the array : "<<endl;
    int target=0;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int inp;
        cin>>inp;
        target+=inp;
        arr.push_back(inp);
    }
    bool ans;
    if(target&1){
        ans=false;
    }
    else{
        ans=isPresent(arr,target/2,n);
    }

    if(ans){
        cout<<"Yes, the array can be divided into equal sum subsets."<<endl;
    }
    else{
        cout<<"No, the array can't be divided."<<endl;
    }

return 0;
}