//https://www.codechef.com/LTIME90B/problems/GASOLINE
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

void solve(){
    ll n;
    cin>>n;
    vector<pair<ll, ll> >arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i].first;
    }
    for(int i=0; i<n; i++){
        cin>>arr[i].second;
    }

    sort(arr.begin(), arr.end(), [&](auto &a, auto &b)->bool{
        if(a.second == b.second){
            return a.first<b.first;
        }
        return a.second<b.second;
    });

    ll ans=0;
    ll dist=0;

    for(int i=0; i<n; i++){
        ans += arr[i].first*arr[i].second;
        dist += arr[i].first;

        if(dist>=n){
            ans -= arr[i].second*(dist-n);
            break;
        }
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