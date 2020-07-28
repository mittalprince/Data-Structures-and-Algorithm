// https://www.codechef.com/LTIME85B/problems/MAXAND18
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
    ll n,k;
    cin>>n>>k;

    ll ct[35]={0};

    vector<ll>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
        for(int j=0; j<31; j++){
            if(arr[i]&(1ll<<j)){
                ct[j] += (1<<j);
            }
        }
    }

    // for(int i: ct){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    vector<pair<ll, int> >t;
    for(int i=0; i<31; i++){
        t.push_back({ct[i], i});
    }

    sort(t.begin(), t.end(), [&](const pair<ll, int>&a, const pair<ll, int>&b)->bool{
        if(a.first == b.first)return a.second<b.second;
        return a.first>b.first;
    });

    ll ans=0;
    for(ll i=0; i<min(k, (ll)t.size()); i++){
        ans |= (1<<t[i].second);
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