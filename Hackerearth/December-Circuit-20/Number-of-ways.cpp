//https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/rook-path-142e55ee/editorial/?layout=old
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

	vector<string>arr(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	vector<vector<ll> >dp(n,vector<ll>(m,0)), rows(n,vector<ll>(m,0)), cols(n,vector<ll>(m,0)); 
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			ll ans=0;
			if(i){
				ans += rows[i-1][j];
			}
			if(j){
				ans += cols[i][j-1];
			}
			if(i==0 and j==0){
				ans =1;
			}
			ans %= MOD;
			if(arr[i][j]=='*'){
				dp[i][j]=0;
				rows[i][j]=0;
				cols[i][j]=0;
			}
			else{
				dp[i][j]=ans;
				rows[i][j] = ((i? rows[i-1][j]:0)+ans)%MOD;
				cols[i][j] = ((j? cols[i][j-1]:0)+ans)%MOD;
			}
		}
	}

	cout<<dp[n-1][m-1]<<endl;
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