//https://www.codechef.com/LTIME91B/problems/THREE
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

void solve2(){
	string s;
	cin>>s;

	int ans=0;
	int n=s.length();

	sort(s.begin(), s.end());
	for(int i=0; i<n-2; i++){
		if(s[i]==s[i+1] and s[i+1]==s[i+2]){
			ans++;
			i+=2;
		}
		else if(s[i]==s[i+1] and s[i+1]!=s[i+2]){
			ans++;
			i+=2;
		}
		else if(s[i]!=s[i+1] and s[i+1]==s[i+2]){
			ans++;
			i+=2;
		}
	}
	cout<<ans<<endl;
}


void solve(){
	string s;
	cin>>s;

	ll n=s.length();

	ll ans = n/3;
	ll freq[26]={0};

	for(char i: s){
		freq[i-'a']++;
	}

	ll curr=0;
	for(int i=0; i<26; i++){
		curr += freq[i]/2;
	}
	cout<<min(ans, curr)<<endl;
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