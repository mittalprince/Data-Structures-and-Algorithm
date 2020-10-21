//https://codeforces.com/contest/1433/problem/D
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
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

	int candidate=arr[0];
	bool flag=true;
	for(int i=1; i<n; i++){
		if(arr[i]!=candidate){
			flag=false;
			break;
		}
	}
	if(flag){
		cout<<"NO\n";
		return;
	}

	map<int, vector<int> >m;
	for(int i=0; i<n; i++){
		m[arr[i]].push_back(i+1);
	}

	auto it = m.begin();
	int prev = it->second[0];
	it++;

	cout<<"YES\n";
	while(it !=m.end()){
		for(auto i: it->second){
			cout<<prev<<" "<<i<<endl;
		}
		prev = it->second[0];
		it++;
	}

	it = m.begin();
	if(it->second.size()>1){
		vector<int>t = it->second;
		for(int i=1; i<t.size(); i++){
			cout<<prev<<" "<<t[i]<<endl;
		}
	}
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