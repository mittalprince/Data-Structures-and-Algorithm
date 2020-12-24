//https://www.codechef.com/COOK125B/problems/SDSTRING
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
	string s;
	cin>>s;

	ll n=s.length();
	if(n&1){
		cout<<"-1\n";
		return;
	}

	ll one=0, zero=0;
	for(char i: s){
		if(i=='1')one++;
		else zero++;
	}

	if(one==0 or zero==0){
		cout<<"-1\n";
		return;
	}

	ll diff = abs(one-zero);
	cout<<diff/2<<endl;
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