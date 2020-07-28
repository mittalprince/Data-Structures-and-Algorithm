#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<set>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007
#define MAX 1005

// jitne component, utne kingdom.
// So question is basically, what will be max edge weight when we have still n totalComponets.
// so lesser the kingdom higher will be the edge cost.

bool consider[MAX][MAX]={false};
vector<vector<ll> >pos, edges;
double ans[MAX]={0.0};
ll n,q,ct=0;

ll dist(const vector<ll>&a, const vector<ll>&b){
    return ((a[0]-b[0])*(a[0]-b[0])) + ((a[1]-b[1])*(a[1]-b[1]));
}

class DSU{
    vector<ll>parent, rank;
    ll V;

    public:
    DSU(ll v){
        parent = vector<ll>(v);
        rank = vector<ll>(v, 0);
        V = v;
        for(ll i=0; i<V; i++){
            parent[i]=i;
        }
    }

    ll get(ll a){
        if(parent[a] == a)return a;
        return parent[a] = get(parent[a]);
    }

    void union_sets(ll a, ll b){
        a = get(a);
        b = get(b);

        if(a != b){
            if(rank[a]<rank[b])swap(a,b);
            parent[b]=a;
            if(rank[a]==rank[b])rank[a]++;
            V--;
        }
    }

    bool isConsideredAllVertice(){
        return V==1;
    }
};

int main(){
    fstIO

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    cin>>n;
    for(ll i=0; i<n; i++){
        ll u,v;
        cin>>u>>v;
        if(!consider[u][v]){
            pos.push_back({u,v});
            consider[u][v]=true;
            ct++;
        }
    }

    n = ct;
    for(ll i=0; i<n; i++){
        for(ll j=i+1; j<n; j++){
            ll u=i;
            ll v=j;
            ll w = dist(pos[i], pos[j]);

            edges.push_back({w,u,v});
        }
    }

    sort(edges.begin(), edges.end());

    DSU g(n);
    ll totalComponents = n;

    for(ll i=0; i<edges.size(); i++){
        ll u=edges[i][1];
        ll v=edges[i][2];
        ll w=edges[i][0];

        if(g.get(u) != g.get(v)){
            totalComponents--;
            ans[totalComponents] = w; // since we req to have less than or equal to K and
            // as sorted by w so all edges considered before that will have val <=k
            g.union_sets(u,v);
        }
    }

    cin>>q;
    while(q--){
        ll i;
        cin>>i;
        double k = sqrt(ans[i]);
        cout<<fixed<<setprecision(10)<<k<<endl;
    }
    return 0;
}