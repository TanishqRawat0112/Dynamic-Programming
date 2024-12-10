#include<iostream>
#include<vector>
using namespace std;

int burstBalloons(vector<int>&balloons,int i,int j){
    if(i>j)return 0;
    int ans = INT_MIN;
    for(int k=i;k<=j;k++){
        int tempAns = burstBalloons(balloons,i,k-1) + burstBalloons(balloons,k+1,j) + (balloons[i-1]*balloons[k]*balloons[j+1]);
        ans=max(ans,tempAns);
    }
    return ans;
}
 
int main(){
    int n;
    cout<<"Enter the number of balloons : ";
    cin>>n;

    vector<int>balloons(n);
    cout<<"Enter the points of balloons : "<<endl;
    for(int i=0;i<n;i++){
        cin>>balloons[i];
    }

    balloons.push_back(1);
    balloons.insert(balloons.begin(),1);

    int ans = burstBalloons(balloons,1,n);
    cout<<"The maximum coins that can be achieved will be : "<<ans<<endl;
return 0;
}