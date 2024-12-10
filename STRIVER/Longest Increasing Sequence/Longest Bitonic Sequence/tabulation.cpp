#include<iostream>
#include<vector>
using namespace std;

int lis(vector<int>&arr,int n){
    vector<int>dp1(n,1),dp2(n,1);
    for(int i = 0; i<n; i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] && 1+dp1[j]>dp1[i]){
                dp1[i] = 1 + dp1[j];
            }
        }
    }

    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(arr[j]<arr[i] && 1+dp2[j]>dp2[i]){
                dp2[i]=1+dp2[j];
            }
        }
    }

    vector<int>res(n,0);
    int ans = 0;
    for(int i=0;i<n;i++){
        if(dp1[i]!=1 && dp2[i]!=1){
            res[i] = dp1[i] + dp2[i] - 1;
        }
        ans=max(ans,res[i]);
    }

    return ans;
    
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

    int ans = lis(arr,n);

    cout<<"The length of Longest Bitonic Sequence is : "<<ans<<endl;


return 0;
}