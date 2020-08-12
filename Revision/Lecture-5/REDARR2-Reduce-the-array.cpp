// https://www.spoj.com/problems/REDARR2/
#include<iostream>
#include<vector>
#include<queue>
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
    int n;
    cin>>n;
    priority_queue<ll, vector<ll>, greater<ll> >pq;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        pq.push(x);
    }

    ll ans=0;
    while(pq.size()>1){
        ll a=pq.top(); pq.pop();
        ll b=pq.top(); pq.pop();

        ans += (a+b);
        pq.push(a+b);
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