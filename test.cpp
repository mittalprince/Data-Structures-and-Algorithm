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


void solve(){
	int n;
	cin>>n;
	vector<int>arr(n);
	ip(arr, n);
	vector<int>prefix(n, 0), suffix(n, 0);
	prefix[0]=arr[0];
	suffix[n-1] = arr[n-1];
	for(int i=1; i<n; i++){
		prefix[i] += prefix[i-1]+arr[i];
	}
	for(int i=n-2; i>=0; i--){
		suffix[i] += suffix[i+1]+arr[i];
	}
	int ans=-1;
	for(int i=1; i<n-1; i++){
		if(prefix[i] == suffix[i]){
			ans = i;
			break;
		}
	}
	cout<<ans<<endl;
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