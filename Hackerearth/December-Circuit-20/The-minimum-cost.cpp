//https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/min-cost-2-fe2d3308/
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
	ll n,c01, c10;
	cin>>n>>c01>>c10;

	ll arr[n];
	ip(arr, n);

	// odd par 0 hoo sare
	ll one=0, zero=0;
	for(int i=0; i<n; i++){
		if(i&1){
			one += arr[i]==1;
		}
		else{
			zero += arr[i]==0;
		}
	}

	ll ans = one*c10 + zero*c01;

	one=0,zero=0;
	// odd par sare 1 hoo
	for(int i=0; i<n; i++){
		if(i&1){
			zero += arr[i]==0;
		}
		else{
			one += arr[i]==1;
		}
	}
	ans = min(ans, zero*c01 + one*c10);
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