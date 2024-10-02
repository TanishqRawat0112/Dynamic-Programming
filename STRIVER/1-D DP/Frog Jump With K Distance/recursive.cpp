#include<iostream>
#include<vector>
using namespace std;

int frogJump(vector<int>&stones,int n,int k){
    if(n==0)return 0;
    int minEnergy = INT_MAX/2;
    for(int i = 1;i<=k;i++){
        int energy = INT_MAX;
        if((n-i)>=0){
            energy = abs(stones[n]-stones[n-i]) + frogJump(stones,n-i,k);
            minEnergy=min(minEnergy,energy);
        }
    }
    return minEnergy;
}
 
int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    vector<int>stones(n);
    cout<<"Enter the stones : ";
    for(int i=0;i<n;i++){
        cin>>stones[i];
    }

    int k;
    cout<<"Enter the maximum jump allowed : ";
    cin>>k;

    int ans = frogJump(stones,n-1,k);

    cout<<"The minimum energy spent will be : "<<ans<<endl;
return 0;
}