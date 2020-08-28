// https://www.hackerrank.com/challenges/journey-to-the-moon/problem?h_r=profile
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
#define MAX 100005

class DSU{
    vector<ll>parent, rank;
    ll totalComponents, V;

    public:
    DSU(ll v){
        V =v;
        parent.resize(v);
        rank.resize(v);
        for(int i=0; i<v; i++){
            parent[i]=i;
            rank[i]=1;
        }
        totalComponents=v;
    }

    ll find(ll a){
        if(a == parent[a])return a;
        return parent[a]=find(parent[a]);
    }
    
    void merge(ll a, ll b){
        a = find(a);
        b = find(b);

        if(a!=b){
            if(rank[a]<rank[b])swap(a,b);
            parent[b]=a;
            rank[a]+=rank[b];
            totalComponents--;
        }
    }

    ll getRank(ll a){
        return rank[a];
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n,m;
    cin>>n>>m;

    DSU g(n);

    for(int i=0; i<m; i++){
        ll u,v;
        cin>>u>>v;
        g.merge(u,v);
    }
    ll ans=0;
    for(int i=0; i<n; i++){
        if(i == g.find(i)){
            ans += g.getRank(i)*(n-g.getRank(i));
        }
    }

    cout<<(ans/2)<<endl;
    
    return 0;
}