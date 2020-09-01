// https://codeforces.com/contest/1281/problem/E
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<cassert>
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
#define MAX 200005

vector<pair<ll, ll> >adj[MAX];

void solve(){
    ll n;
    cin>>n;

    ll m = 2*n;
    for(ll i=0; i<m-1; i++){
        ll u,v,w;
        cin>>u>>v>>w;
        u--; v--;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<bool>visited(m, 0);
    vector<ll>ct(m, 0);

    ll minDist=0, maxDist=0;

    function<ll(ll)>maxDist_helper;
    maxDist_helper = [&](ll src)->ll{
        visited[src]=true;
        ct[src]=1;

        for(pair<ll, ll>child: adj[src]){
            ll dx = child.second;
            if(!visited[child.first]){
                ct[src] += maxDist_helper(child.first);
                ll right = ct[child.first];
                ll left = m-right;
                maxDist += min(left, right)*dx;
            }
        }
        return ct[src];
    };

    function<ll(ll)>minDist_helper;
    minDist_helper = [&](ll src)->ll{
        visited[src]=true;
        ct[src]=1;

        for(pair<ll, ll>child: adj[src]){
            ll dx = child.second;
            if(!visited[child.first]){
                ct[src] += minDist_helper(child.first);
                ll right = ct[child.first]%2;
                ll left = (m-right)%2;
                minDist += min(left, right)*dx;
            }
        }
        return ct[src];
    };

    maxDist_helper(0);
    visited = vector<bool>(m, 0);
    ct = vector<ll>(m, 0);

    minDist_helper(0);

    cout<<minDist<<" "<<maxDist<<endl;
    for(ll i=0; i<=m; i++){
        adj[i].clear();
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