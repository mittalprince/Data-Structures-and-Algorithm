#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

int solve(vector<int>&arr){
	int n=arr.size();
	if(n==1 || arr[0]!= arr[1])return arr[0];

	int s=0, e=n-1;
	while(s<e){
		int mid = (s+e)/2;
		if(mid&1){
			if(arr[mid]==arr[mid-1])s=mid+1;
			else e=mid;
		}
		else{
			if(mid<n+1 and arr[mid]==arr[mid+1])s=mid+1;
			else e=mid;
		}
	}
	return arr[s];
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> arr(n);
		ip(arr, n);
		cout<<solve(arr)<<endl;
	}
	return 0;
}

/*
2
11
1 1 2 2 3 4 4 5 5 6 6
11
1 1 2 2 3 3 4 4 5 5 6
*/