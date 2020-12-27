//https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/multiple-occurence-97c00160/
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

void solve(){
	int n;
	cin>>n;
	unordered_map<int, pair<int, int> >m;

	int arr[n];
	ip(arr, n);

	for(int i=0; i<n; i++){
		if(m.count(arr[i])){
			m[arr[i]].second=i;
		}
		else m[arr[i]]={i,i};
	}

	ll ans=0;
	for(auto it: m){
		ans += it.second.second-it.second.first;
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