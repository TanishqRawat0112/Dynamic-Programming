#include<iostream>
#include<vector>
using namespace std;

int ninjaTraining(vector<vector<int> >&training,int n){
    int prevC1=0;
    int prevC2=0;
    int prevC3=0;
    for(int i=1;i<=n;i++){
        int curr1 =0, curr2 = 0, curr3 = 0;
        for(int j=1;j<=3;j++){
            if(j==1){
                curr1=training[i-1][j-1] + max(prevC2,prevC3);
            }
            if(j==2){
                curr2 = training[i-1][j-1] + max(prevC1,prevC3);
            }
            if(j==3){
                curr3 = training[i-1][j-1] + max(prevC1,prevC2);
            }
        }
        prevC1 = curr1;
        prevC2 = curr2;
        prevC3 = curr3;
    }
    return max(prevC1,max(prevC2,prevC3));
}
 
int main(){
    int n;
    cout<<"Enter the number of days : ";
    cin>>n;

    vector<vector<int> >training(n,vector<int>(3,0));
    cout<<"Enter the training points for each day : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>training[i][j];
        }
    }

    int ans = ninjaTraining(training,n);

    cout<<"Maximum points that can be earned are : "<<ans<<endl;
return 0;
}