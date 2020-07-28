#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

class DSU{
    vector<ll>parent, rank;
    ll V;
    public:

    DSU(ll v){
        V = v;
        parent = vector<ll>(v+1);
        rank = vector<ll>(v+1);

        for(ll i=0; i<=v; i++){
            parent[i]=i;
        }
    }

    void inputRank(){
        for(ll i=1; i<=V; i++){
            cin>>rank[i];
        }
    }

    ll getRank(ll a){
        return rank[a];
    }

    ll get(ll a){
        if(parent[a] == a) return a;
        return parent[a] = get(parent[a]);
    }

    void union_sets(ll a, ll b){
        a = get(a);
        b = get(b);

        if(a != b){
            if(rank[a]>rank[b]){
                swap(a, b);
            }
            parent[b]=a;
        }
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    #endif

    ll n,k;
    cin>>n>>k;

    DSU g(n);

    g.inputRank();

    for(int i=0; i<k; i++){
        ll u,v;
        cin>>u>>v;
        g.union_sets(u,v);
    }
    ll ans=0;
    for(int i=1; i<=n; i++){
        if(g.get(i) == i){
            ans += g.getRank(i);
        }
    }
    cout<<ans<<endl;
    return 0;
}