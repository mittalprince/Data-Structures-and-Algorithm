//https://codeforces.com/contest/1433/problem/C
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
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

void solve(){
	int n;
	cin>>n;
	vector<int>arr(n);
	ip(arr, n);
	vector<int>brr = arr;

	sort(brr.begin(), brr.end());
	if(brr[0] == brr[n-1]){
		cout<<"-1\n";
		return;
	}

	int mx=brr[n-1];
	for(int i=0; i<n-1; i++){
		if(arr[i]==mx and arr[i+1]!=mx){
			cout<<i+1<<endl;
			return;
		}
	}

	for(int i=1; i<n; i++){
		if(arr[i]==mx and arr[i-1]!=mx){
			cout<<i+1<<endl;
			return;
		}
	}

	cout<<"-1\n";

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}