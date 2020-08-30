// https://www.codechef.com/problems/ALIENIN
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
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
#define ppi pair<ll, ll>

vector<ppi>arr;
ll n, d;

bool canPossible(double mid){
    double start = arr[0].first;
	for(int i=1; i<n; i++){
		if((double)(arr[i].second) < (double)(start+mid)){return 0;}
		start = max(start+mid, (double)arr[i].first);
	}
	return 1;
}

void solve(){
    cin>>n>>d;
    vector<ll>t(n);
    ip(t, n);

    for(int i=0; i<n; i++){
        arr.push_back({t[i], (t[i]+d)});
    }

    sort(arr.begin(), arr.end(), [&](const ppi a, const ppi b)->bool{
        if(a.first==b.first)return a.second<b.second;
        return a.first<b.first; 
    });

    double ans=0;
    double l=0, r=(double)(1e10);
    while((r-l)>=1e-6){
        double mid = (double)(r+l)/2;
        // cout<<l<<" "<<r<<" "<<ans<<endl;

        if(canPossible(mid)){
            // cout<<ans<<endl;
            ans=mid;
            l=mid;
        }
        else r=mid;
    }
    // cout<<l<<" "<<r<<" "<<ans<<endl;
    cout<<ans<<endl;
    arr.clear();
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cout<<fixed<<setprecision(10);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}