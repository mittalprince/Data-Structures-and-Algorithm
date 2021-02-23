#include<iostream>
#include<vector>
#include<unordered_map>
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

ll factorial(ll n){
	if(n<=1)return 1;
	return factorial(n-1)*n;
}

void solve(){
	string x,y;
	cin>>x>>y;
	bool friendly = true;
	if(x[0]=='0' or y[0]=='0')friendly=false;
	unordered_map<int, ll> sx, sy;
	for(ll i=0; i<x.length(); i++){
		sx[x[i]-'0']++;
	}
	for(ll i=0; i<y.length(); i++){
		sy[y[i]-'0']++;
	}
	for(auto it: sx){
		if(it.second != sy[it.first]){
			friendly=false;
			break;
		}
	}
	ll denomiator = 1;
	ll numerator = 0;
	if(friendly){
		for(auto it: sx){
			denomiator *= factorial(it.second);
		}
		if(sx.count(0)){
			numerator = factorial(x.length() - 1) * (x.length()-sx[0]);
		}
		else numerator = factorial(x.length());
	}
	else{
		for (auto it : sy){
			denomiator *= factorial(it.second);
		}
		if (sy.count(0)){
			numerator = factorial(y.length() - 1) * (y.length() - sy[0]);
		}
		else
			numerator = factorial(y.length());
	}
	ll ans = numerator/denomiator;
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