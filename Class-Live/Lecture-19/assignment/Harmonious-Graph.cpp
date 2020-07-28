// Harmonious Graph
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

/*
Logic: Used DSU

Here we simple merge given edges and make parent those vertex whose val is large.

Now we use greedy appraoch we pick vectex one by one and run a loop from vertx+1 to its parent
and inside we get any node whose parent is not equal to this means there is no edge we merge them by adding an edge
so increment ans and update the parent to max of these two parent, as after edge we can have to visit other nodes also
of diff parent.

*/

class DSU{
    vector<ll>parent;
    ll V;

    public:

    DSU(ll v){
        V = v;
        parent = vector<ll>(V+1);
        for(ll i=0; i<=V; i++){
            parent[i]=i;
        }
    }

    ll get(ll a){
        if(parent[a] == a)return parent[a];
        return parent[a] = get(parent[a]);
    }

    void union_sets(ll a, ll b){
        a = get(a);
        b = get(b);

        if(a != b){
            if(a<b){
                swap(a, b);
            }
            parent[b]=a;
        }
    }
};

int main(){
    fstIO;

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    
    ll n,m;
    cin>>n>>m;

    DSU g(n);

    for(ll i=0; i<m; i++){
        ll u,v;
        cin>>u>>v;
        g.union_sets(u, v);
    }

    ll ans=0;

    for(ll i=1; i<=n; i++){
        ll parent = g.get(i);

        for(ll j=i+1; j<parent; j++){
            ll new_parent = g.get(j);
            if(new_parent != parent){
                g.union_sets(parent, new_parent);
                parent = max(parent, new_parent);
                ans++;
            }
        }
        i=parent; // as if we have i to parent all nodes then we also have (i+1) to parent all nodes.
        // this is optimization otherwise give tle
    }
    cout<<ans<<endl;
    return 0;
}