#include<iostream>
#include<vector>
using namespace std;

bool isPresent(vector<int>&arr,int target,int n){
    if(target==0)return true;
    if(n==0)return false;
    if(arr[n-1]<=target){
        if(isPresent(arr,target-arr[n-1],n-1)==true){
            return true;
        }
        if(isPresent(arr,target,n-1)==true){
            return true;
        }
    }
    else{
        if(isPresent(arr,target,n-1)==true){
            return true;
        }
    }
    return false;
}
 
int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    cout<<"Enter the array : ";
    vector<int>arr;
    for(int i=0;i<n;i++){
        int inp;
        cin>>inp;
        arr.push_back(inp);
    }

    int target;
    cout<<"Enter the target : ";
    cin>>target;

    bool ans=isPresent(arr,target,n);

    if(ans){
        cout<<"Yes , the subset is present whose sum equals target."<<endl;
    }
    else{
        cout<<"No, there is no such subset present."<<endl;
    }
return 0;
}