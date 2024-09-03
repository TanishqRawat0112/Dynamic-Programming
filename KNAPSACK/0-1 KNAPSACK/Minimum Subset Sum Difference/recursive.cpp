#include<iostream>
#include<vector>
using namespace std;

int min_subset_diff(vector<int>&array,int n,int sum,int sumLeft){
    if(n<0){
        return abs(sum-sumLeft);
    }
    //picking the element:
    int pick=min_subset_diff(array,n-1,sum-array[n],sumLeft+array[n]);
    //not picking the element:
    int notPick=min_subset_diff(array,n-1,sum,sumLeft);

    //return the min difference:
    return min(pick,notPick);
}
 
int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    vector<int>array(n);
    int sum=0;
    cout<<"Enter the array : "<<endl;
    for(int i=0;i<n;i++){
        cin>>array[i];
        sum+=array[i];
    }

    int ans=min_subset_diff(array,n-1,sum,0);

    cout<<"The minimum Subset sum difference is : "<<ans<<endl;


return 0;
}