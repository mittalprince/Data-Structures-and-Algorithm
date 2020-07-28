#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
#define MAX 100005

class DSU{
    vector<ll>parent, rank;
    public:

    DSU(ll n){
        parent.resize(n), rank.resize(n);
        for(ll i=0; i<n; i++){
            parent[i]=i;
            rank[i]=1;
        }
    }

    ll get(ll a){
        if(parent[a] == a){
            return a;
        }
        return parent[a] = get(parent[a]);
    }

    void union_sets(ll a, ll b){
        a = get(a);
        b = get(b);

        if(a != b){
            if(rank[a]<rank[b]){
                swap(a, b);
            }
            parent[b]=a;
            rank[a] += rank[b];
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

    ll n,p;
    cin>>n>>p;

    DSU g(MAX+1);

    for(int i=0; i<p; i++){
        ll u,v;
        cin>>u>>v;
        g.union_sets(u, v);
    }
    
    ll ans=0;
    for(int i=0; i<n; i++){
        if(i == g.get(i)){
            ans += g.getRank(i)*(n-g.getRank(i));
        }
    }
    cout<<(ans/2)<<endl;
    return 0;
}