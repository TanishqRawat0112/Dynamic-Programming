#include<iostream>
#include<vector>
using namespace std;

int mcm(vector<int>&arr,int i,int j){
    if(i>=j)return 0;
    int ans = INT_MAX;
    for(int k=i;k<j;k++){
        int tempAns = mcm(arr,i,k) + mcm(arr,k+1,j) + (arr[i-1]*arr[k]*arr[j]);
        ans = min(ans,tempAns);
    }
    return ans;
}

 
int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    cout<<"Enter the array : "<<endl;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ans = mcm(arr,1,n-1);

    cout<<"The minimum answer from the matrix chain multiplication will be : "<<ans<<endl;
return 0;
}