//https://codeforces.com/contest/1447/problem/C
#include<iostream>
#include<vector>
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
	ll n,w;
	cin>>n>>w;
	vector<pair<ll ,ll> >arr(n);

	for(int i=0; i<n; i++){
		cin>>arr[i].first;
		arr[i].second = i+1;
	}
	sort(arr.rbegin(), arr.rend());

	vector<ll>ans;
	ll wt_taken=0;
	for(pair<ll, ll> it:arr){
		if(it.first>w)continue;
		wt_taken += it.first;
		ans.push_back(it.second);
		if(wt_taken*2 >= w){
			cout<<ans.size()<<endl;
			for(int i: ans){
				cout<<i<<" ";
			}
			cout<<endl;
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