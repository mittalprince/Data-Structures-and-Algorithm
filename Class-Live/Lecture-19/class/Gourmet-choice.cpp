// Gourmet choice
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<list>
#include<unordered_map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
#define MAX 2005

// Logic Used -> DFS, DSU, DP, Cycle Detection
/*
We basically first make a directed grpah of nodes tyhat have greater or less val than other node.
Node that have greater val will become parent and less val node will become child.
We use same logic to build graph edges and the node that have same val(=) we conider only one node
of this type that is consdiet only their superparent and insert into DSU and join them.

After building the grpah we find depth of each node as we lower the depth lower the node marks,
so all leat nodes have depth 1 and also their marks. So we cal depth and use it as their marks

Now the case when ans dones exist is when there exist a cycle in directed graph, so to detect this
we use same logic to detect cycle in directed graph
*/

vector<pair<ll ,ll> >edges; // store edges of graph
vector<ll> adj[MAX]; // maintain a graph as adjanceny list
bool visited[MAX]={0};
bool is_cycle_present=false; // to check whether cycle exist or not if yes then ans is always No
ll depth[MAX]={0}; // store depth of each node

bool kyaNodeAlreadyVisistedHai[MAX]={0}; // use as stack, use same logic which we use to detect cycle in directed graph
// means we maintain a instak which whether the node is already present in tack or not, if yes then cycle exist

class DSU{
    vector<ll> parent, rank;
    ll totalComponents;
    public:

    DSU(ll n){
        totalComponents = n;
        parent = vector<ll>(n);
        rank = vector<ll>(n);

        for(int i=0; i<n; i++){
            parent[i]=i;
            rank[i]=0;
        }
    }

    ll get(ll a){
        if(parent[a] == a){
            return parent[a];
        }

        return parent[a] = get(parent[a]);
    }

    void union_sets(ll a, ll b){
        a = get(a); // get parent of a
        b = get(b); // get parent of b
 
        if(a!=b){// if both are not in same set then combine them
            if(rank[a]<rank[b]){
                swap(a, b);
            }
            parent[b]=a;
            if(rank[a]==rank[b]) rank[a]++;
            totalComponents--;
        }
    }
};


void FindDepth(ll src){
    if(visited[src])return; // dp works here

    if(is_cycle_present) return; // is cycle present we know ans is No so just return

    if(kyaNodeAlreadyVisistedHai[src]){
        is_cycle_present=true;
        return;
    }

    kyaNodeAlreadyVisistedHai[src]=true;

    ll d=0;
    for(ll child: adj[src]){
        FindDepth(child);
        d = max(d, depth[child]);
    }
    depth[src] = d+1;
    kyaNodeAlreadyVisistedHai[src]=false;
    visited[src]=true;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n,m;
    cin>>n>>m;
    
    // use DSU for the nodes that are on the same level
    // so we cal for superparent node and assign the val to all its children
    DSU g(n+m); //take dsu of size n+m as max possible nodes that lie on same level are n+m

    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            char ch;
            cin>>ch;

            if(ch == '='){// two nodes have same val, so insert into dsu and make set
                g.union_sets(i, n+j);
            }
            else if(ch == '>'){// if ith node val is greter than make a directed node from i to j
                // as lesser val node will be child of greater node val
                edges.push_back({i, n+j});
            }
            else{// if jth node has greater val that make ddirected edge from j to i
                edges.push_back({n+j, i});
            }
        }
    }

    // Make graph
    for(pair<ll, ll> edge: edges){
        // here we make graph of only superparent as we consider them only, beacuse their val can also
        // assign to their child
        adj[g.get(edge.first)].push_back(g.get(edge.second));
    }

    //Now we find depth of each node and use the same depth to assign them marks
    for(ll i=0; i<n+m; i++){
        if(!visited[i]){
            FindDepth(g.get(i));
        }
    }

    if(is_cycle_present){
        cout<<"No\n";
        return 0;
    }

    cout<<"Yes\n";
    for(int i=0; i<n; i++){
        cout<<depth[g.get(i)]<<" ";
    }
    cout<<endl;
    for(int j=0; j<m; j++){
        cout<<depth[g.get(n+j)]<<" ";
    }
    cout<<endl;

    return 0;
}