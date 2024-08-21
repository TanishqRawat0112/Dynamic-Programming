#include <iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    vector<int>arr(n);
	    int sum=0;
	    int mod=1e9+7;
	    priority_queue<int,vector<int>,greater<int> >pq;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        sum+=arr[i];
	        pq.push(arr[i]);
	    }
	    
	    while(k--){
	        int num=pq.top();
	        pq.pop();
	        sum+=num;
	        sum%=mod;
	        pq.push(2*num);
	    }
	    cout<<sum<<endl;
	}
}
