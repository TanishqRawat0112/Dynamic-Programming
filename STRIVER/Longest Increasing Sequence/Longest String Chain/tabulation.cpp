#include<iostream>
#include<vector>
using namespace std;

bool compare(string x,string y){
    int n1 = x.size();
    int n2 = y.size();
    if(n1+1!=n2)return false;
    int left = 0;
    int right = 0;

    while(left<n1 && right<n2){
        if(x[left]==y[right]){
            left++;
        }
        right++;
    }
    if(left==n1)return true;
    return false;
}

int lsc(vector<string>&arr,int n){
    vector<int>dp(n,1);
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(compare(arr[j],arr[i]) && 1+dp[j]>dp[i]){
                dp[i] = 1 + dp[j];
            }
        }
        ans=max(ans,dp[i]);
    }
    return ans;
}
 
int main(){
    int n ;
    cout<<"Enter the size of the vector : ";
    cin>>n;

    vector<string>arr(n);
    cout<<"Enter the array of strings : "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ans = lsc(arr,n);

    cout<<"The length of the longest string chain is : "<<ans<<endl;

    
return 0;
}