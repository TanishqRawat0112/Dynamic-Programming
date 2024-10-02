#include<iostream>
#include<vector>
using namespace std;

int ninjaTraining(vector<vector<int> >&training,int n,int act){
    if(n==0)return 0;
    int ans = 0;
    for(int i=0;i<3;i++){
        if(i!=act){
            ans = max(ans,ninjaTraining(training,n-1,i) + training[n-1][i]);
        }
    }
    return ans;
}
 
int main(){
    int n;
    cout<<"Enter the number of days : ";
    cin>>n;

    vector<vector<int> >training(n,vector<int>(3,0));
    cout<<"Enter the training points for each day : ";
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>training[i][j];
        }
    }

    int ans = ninjaTraining(training,n,-1);

    cout<<"Maximum points that can be earned are : "<<ans<<endl;
return 0;
}