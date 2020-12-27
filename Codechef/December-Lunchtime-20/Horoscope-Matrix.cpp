//https://www.codechef.com/LTIME91B/problems/HRSCPMTR
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
	int arr[n][m];

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>arr[i][j];
		}
	}

	int ct=0;
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			ct += (arr[i][j]!=arr[i-1][j-1]);
		}
	}

	int q;
	cin>>q;
	while(q--){
		int x,y,v;
		cin>>x>>y>>v;

		x--;y--;
		if(x-1>=0 and y-1>=0){
			ct -= (arr[x][y]!=arr[x-1][y-1]);
		}
		if(x+1<n and y+1<m){
			ct -= (arr[x][y]!=arr[x+1][y+1]);
		}

		arr[x][y]=v;

		if(x-1>=0 and y-1>=0){
			ct += (arr[x][y]!=arr[x-1][y-1]);
		}
		if(x+1<n and y+1<m){
			ct += (arr[x][y]!=arr[x+1][y+1]);
		}

		if(ct==0){
			cout<<"YES\n";
		}
		else cout<<"NO\n";
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