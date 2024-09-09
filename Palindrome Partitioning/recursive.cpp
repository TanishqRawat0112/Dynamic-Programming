#include<iostream>
using namespace std;

bool isPalindrome(string x,int i,int j){
    while(i<j){
        if(x[i]!=x[j])return false;
        i++;
        j--;
    }
    return true;
}

int minPart(string x,int i,int j){
    if(i>=j){
        return 0;
    }
    if(isPalindrome(x,i,j)){
        return 0;
    }
    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        int tempAns = 1 + minPart(x,i,k) + minPart(x,k+1,j);
        ans=min(ans,tempAns);
    }
    return ans;
}
 
int main(){
    string x;
    cout<<"Enter the string : ";
    cin>>x;

    int n = x.size();

    int ans=minPart(x,0,n-1);

    cout<<"The Minimum Number of Partitions will be : "<<ans<<endl;

return 0;
}