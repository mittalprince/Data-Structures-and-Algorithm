// https://www.codechef.com/CENS2020/problems/CENS20A
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
    ll n,m;
    cin>>n>>m;

    vector<string>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<vector<ll> >prefix(n+1, vector<ll>(m+1, 0));
    ll q;
    cin>>q;

    for(int i=0; i<q; i++){
        ll lx,ly,rx,ry;
        cin>>lx>>ly>>rx>>ry;
        lx--;ly--;rx--;ry--;

        prefix[lx][ly]++; prefix[lx][ry+1]--;
        prefix[rx+1][ly]--; prefix[rx+1][ry+1]++;
    }
    
    for(int i=0; i<n; i++){
		ll ct=0;
		for(int j=0; j<m; j++){
			prefix[i][j] += ct;
			ct = prefix[i][j];
		}
	}

	for(int j=0; j<m; j++){
		ll ct=0;
		for(int i=0; i<n; i++){
			prefix[i][j] += ct;
			ct = prefix[i][j];
		}
	}

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(prefix[i][j]&1){
                if(arr[i][j]=='1')arr[i][j]='0';
                else arr[i][j]='1';
            }
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}