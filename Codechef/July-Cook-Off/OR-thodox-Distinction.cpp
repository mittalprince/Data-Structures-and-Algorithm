// https://www.codechef.com/COOK120B/problems/ORTHODOX
#include<iostream>
#include<vector>
#include<unordered_set>
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

ll subarrayBitwiseORs(vector<ll>& A) {
    unordered_set<ll> res;
    unordered_set<ll> cur;
    unordered_set<ll> cur2;
    for (ll a:A){
        cur2 = {a};
        for (ll c:cur){
            cur2.insert(c | a);
        }
        cur = cur2;
        res.insert(cur.begin(), cur.end());
    }
    return res.size();
}

void solve(){
    ll n;
    cin>>n;
    vector<ll>arr(n);

    ip(arr, n);
    ll t = subarrayBitwiseORs(arr);
    ll a = (n*(n+1))/2;
    if(t==a){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
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