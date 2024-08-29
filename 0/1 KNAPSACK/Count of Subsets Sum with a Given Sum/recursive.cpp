#include<iostream>
#include<vector>
using namespace std;

int count_subsets(vector<int>&array,int n,int sum){
    if(sum==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    int ans=0;
    if(array[n]<=sum){
        ans+=(count_subsets(array,n-1,sum-array[n]));
        ans+=(count_subsets(array,n-1,sum));
    }
    else{
        ans+=(count_subsets(array,n-1,sum));
    }
    return ans;
}
 
int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    vector<int>array(n);
    cout<<"Enter the array : ";
    for(int i=0;i<n;i++){
        cin>>array[i];
    }

    int sum;
    cout<<"Enter the Given Sum : ";
    cin>>sum;

    int ans=count_subsets(array,n-1,sum);

    cout<<"The Number of Subsets with given sum will be : "<<ans<<endl;
return 0;
}