//https://codeforces.com/contest/1433/problem/E
#include<iostream>
#include<vector>
#include<cmath>
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

ll check(ll n){
    ll fact=1;
    for(int i=1;i<=n;i++)fact=fact*i;
    return fact;
}

void solve(){
	ll n;
	cin >> n;
	ll A = check(n);
	ll B = check(n / 2);
	ll C = check(n / 2 - 1);
	cout << (((A / (B * B)) * (C * C)) / 2) << endl;
	return;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t=1;
// 	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}