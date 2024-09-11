//1 ,2 ,3 , 4, 5, 6.
//Unbounded Knapsack
//Target Given
//Variation of Ques Unbounded kanpsack

//n=5
//0 -> 1 ({})
//1 -> 1 (1)
//2 -> 2 (1+1,2)
//3 -> 4(1+1+1,1+2,2+1,3)
//4 ->8(1+1+1+1,1+1+2,1+2+1,2+1+1,2+2,1+3,3+1,4)
//5 -> 16(1+1+1+1+1,1+1+1+2,1+1+2+1,1+2+1+1,2+1+1+1,1+1+3,1+3+1,3+1+1,1+4,4+1,1+2+2,2+1+2,2+2+1,2+3,3+2,5)


#include<iostream>
#include<vector>
using namespace std;

int numWays(int target){
    if(target<=1)return pow(2,0);
    return pow(2,target-1);  
}
 
int main(){
    int target;
    cout<<"Enter the target : ";
    cin>>target;

    int ans = numWays(target);

    cout<<"The number of ways to throw a dice to get the desired target will be : "<<ans<<endl;
return 0;
}