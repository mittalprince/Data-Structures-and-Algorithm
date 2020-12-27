//https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/alice-and-customer-satisfaction-b6dc3745/description/?layout=old
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
#define pll pair<ll, ll>

void solve(){
	ll n;
	cin>>n;

	vector<pair<pll, ll> >arr;
	ll e=0ll;
	for(int i=0; i<n; i++){
		ll l,r,z;
		cin>>l>>r>>z;
		arr.push_back({{l,r},z});
		e += z;
	}

	sort(arr.begin(), arr.end(), [&](auto a, auto b)->bool{
		return a.first.second<b.first.second;
	});

	ll s=1ll;
	ll ans=e;
	while(s<=e){
		ll mid = (e+s)/2;
		ll req=0ll;
		bool flag=true;
		for(int i=0; i<n; i++){
			ll prod = arr[i].first.second*mid;
			req += arr[i].second;
			if(prod<req){
				flag=false;
				break;
			}
		}
		if(flag){
			ans=mid;
			e=mid-1;
		}
		else s=mid+1;
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