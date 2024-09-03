#include<iostream>
using namespace std;

int longestCommonSubstring(string &s1, string &s2, int i, int j, int count) {
    if (i == 0 || j == 0) {
        return count;
    }
    if (s1[i - 1] == s2[j - 1]) {
        count = longestCommonSubstring(s1, s2, i - 1, j - 1, count + 1);
    }
    int count1 = longestCommonSubstring(s1, s2, i - 1, j, 0);
    int count2 = longestCommonSubstring(s1, s2, i, j - 1, 0);

    return max(count, max(count1, count2));
}
 
int main(){
    string x,y;
    cout<<"Enter the first string : ";
    cin>>x;

    cout<<"Enter the second string : ";
    cin>>y;

    int n=x.length();
    int m=y.length();

    int ans=longestCommonSubstring(x,y,n,m,0);

    cout<<"The length of the longest common subsequence will be : "<<ans<<endl;
return 0;
}