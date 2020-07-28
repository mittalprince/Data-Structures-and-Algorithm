// Chemical table
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

for a particular make union of row and col. Count all superparent.
Now we have to connect all supperparent, so total cost of joining will be total component-1.
 _ _
|1|3|
 - -
|2|4|
 - -

 For this matrix if we have any three cell says (1,2), (2,2), (2,1) we can gen third one and this propeprty hold true
 while using DSU, as for (1,2)->union(1, 4), for (2,2)-> union(2,4) and for (2,1)->union(2,3)

 and we have 
        1
      / | \
      2 4 3
    
like struct so total component will be one and ans will be 0.
But assume we dont have (2,1) then we dont have (1-3) in set. 
Parent[] = {1,1,3,1} will be this and here we have two superparent, so ans will 2-1=1
*/

class DSU{
    vector<ll>parent, rank;
    
    public:
    DSU(ll n){
        parent = vector<ll>(n);
        rank = vector<ll>(n, 0);

        for(ll i=0; i<n; i++){
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
            if(rank[a]<rank[b]){
                swap(a, b);
            }
            parent[b]=a;
            if(rank[a]==rank[b])rank[a]++;
        }
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n,m,q;
    cin>>n>>m>>q;

    DSU g(n+m);

    for(int i=0; i<q; i++){
        ll x,y;
        cin>>x>>y;
        x--; y--;
        g.union_sets(x, n+y);
    }

    vector<bool>ct(n+m, 0);

    for(int i=0; i<n+m; i++){
        ct[g.get(i)]=true;
    }

    ll ans=0;
    for(int i=0; i<n+m; i++){
        if(ct[i])ans++;
    }

    cout<<ans-1<<endl;
    return 0;
}
