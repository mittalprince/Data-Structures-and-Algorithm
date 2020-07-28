// Jeremy Bearimy
#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<algorithm>
#include<functional>
#include<cassert>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

/*
Logic:
We have to max dist amd min dist travlled while assigning house to 2k people.
we use same logic of HOLI (spoj question)

For Max dist we need to find how many max time we can use a particular edge.
For this we cal no of nodes in subtree in both direction for each edge (in left and right dir).

So ek edge max kitni bar use hogi uske liye hum uss edge ke right and left dono side mein kitni
nodes hai voh count kar lee, qki we need to chnage every person house so for a particular edge ke liye
uske left ke sabhi nodes edges ke right side ki nodes se house changes karegi.

now we tak min of these left,right nodes qki ghar tabhi swap hoga jab people available honge.
so if we have 3 in left and 5 in right toh 3 vale toh right mein ja sakta hai but 5 vale sare nahi sirf 3 
ja sakta hai.

For min dist we want ki hum ek edge ko kitni kam bar use kar sakta hai. So we want ki ek subtree mein nodes
apas mein hi ghar assign kar lee rather than to go in opposite direction as we did in to maximise dist
means if for a particualr node it has 4 nodes in its subtree, we assign house to couple in this substree
rahter than assign house in upper nodes of parent node.

So if in a substree we have even count of nodes we need not to worry as we can assign them house as they are even
But if we have odd nodes then we have to assign a node a house in upper tree(in other component).
So we use concept of mod 2.

so we take min(left, right)%2, this gives min usage of a edge
*/

ll n,m;
// n->total pair of couples, m->total nodes and m-1->total-edges


class Graph{
    ll V;
    unordered_map<ll, list<pair<ll, ll> > >adj;

    public:

    Graph(ll v):V(v){}

    void addEdge(ll u, ll v, ll w, bool bidir=true){
        adj[u].push_back({v, w});
        if(bidir){
            adj[v].push_back({u, w});
        }
    }

    ll MAxDist(){ // return max dist of edges
        unordered_map<ll, bool>visited;
        vector<ll>ct(V, 0);

        ll ans=0;

        function<ll(ll)>max_dist_helper;

        // count no of nodes in substree in one top down direction
        max_dist_helper = [&](ll src)->ll{
            visited[src]=true;
            ct[src]=1;

            for(auto child: adj[src]){
                ll dx = child.second;

                assert(child.first< V);

                if(!visited[child.first]){
                    ct[src] += max_dist_helper(child.first);
                    ll right_nodes = ct[child.first];
                    ll left_nodes = V-ct[child.first];
                    ans += min(left_nodes, right_nodes)*dx;
                }
            }
            // cout<<src<<" "<<ct[src]<<endl;
            return ct[src];
        };

        max_dist_helper(0);
        return ans;
    }

    ll MinDist(){ // return min dist of edges
        unordered_map<ll, bool>visited;
        vector<ll>ct(V, 0);

        ll ans=0;

        function<ll(ll)>min_dist_helper;

        // count no of nodes in substree in top down direction
        min_dist_helper = [&](ll src)->ll{
            visited[src]=true;
            ct[src]=1;

            for(auto child: adj[src]){
                ll dx = child.second;

                assert(child.first < V);

                if(!visited[child.first]){
                    ct[src] += min_dist_helper(child.first);
                    ll right_nodes = (ct[child.first])%2;
                    ll left_nodes = (V-ct[child.first])%2;
                    ans += min(left_nodes, right_nodes)*dx;
                }
            }
            // cout<<src<<" "<<ct[src]<<endl;
            return ct[src];
        };

        min_dist_helper(0);
        return ans;
    }
};

void solve(){;
    cin>>n;
    m = 2*n;

    Graph g(m);

    for(ll i=0; i<m-1; i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g.addEdge(u-1,v-1,w);
    }
    cout<<g.MinDist()<<" "<<g.MAxDist()<<endl;
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