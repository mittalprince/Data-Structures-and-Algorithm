//https://codeforces.com/contest/1447/problem/B
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
	int n,m;
	cin>>n>>m;

	int arr[n*m];
	ip(arr, n*m);
	int neg=0, zero=0;
	ll ans=0;
	int mi = inf;
	for(int i=0; i<n*m; i++){
		ans += abs(arr[i]);
		if(arr[i]<0)neg++;
		if(arr[i]==0)zero++;
		mi = min(mi, abs(arr[i]));
	}

	if(neg%2==0 or (neg+zero)%2==0){
		cout<<ans<<endl;
		return;
	}
	cout<<ans-2*mi<<endl;
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