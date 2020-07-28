#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
#include<bitset>
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

ll compare(ll a,ll b){
	string A=bitset<32>(a).to_string();
	string B=bitset<32>(b).to_string();

	ll i=0;
	while(i<33 && A[i]=='0')i++;
	A.erase(0,i);

	i=0;
	while(i<33 && B[i]=='0')i++;
	B.erase(0,i);

	string ab=A+B;
	string ba=B+A;

	ll AB=stoll(ab, 0, 2);
	ll BA=stoll(ba, 0, 2);

	return abs(AB-BA);
}

void solve(){
    int n;
    cin>>n;
    vector<ll>arr(n);
    ip(arr, n);
    
    sort(arr.rbegin(), arr.rend());
    ll a=arr[0];
    ll b=arr[n-1];

    cout<<compare(a,b)<<endl;
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