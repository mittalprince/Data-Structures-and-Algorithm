// HOLI - Holiday Accommodation
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<list>
#include<functional>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
/*
Logic: we basically use, ki agr hum edges ke weight ke (jo hume given hai) usse maximun kar de
toh ans bhi max hoga.
So we used same logic ki hum ek edge ko max kitne baar use kar sakta hai , uss count ko edge ke weight se
multiply kar doo and repeat same process for all edges and add their sum to get final ans.

So ek edge max kitni bar use hogi uske liye hum uss edge ke right and left dono side mein kitni
nodes hai voh count kar lee, qki we need to chnage every person house so for a particular edge ke liye
uske left ke sabhi nodes edges ke right side ki nodes se house changes karegi.

now we tak min of these left,right nodes qki ghar tabhi swap hoga jab people available honge.
so if we have 3 in left and 5 in right toh 3 vale toh right mein ja sakta hai but 5 vale sare nahi sirf 3 
ja sakta hai.

Now ek edge 1 house swap mein do bari swap hogi ekl bari log left jaeynge and ek bari log right jaynege
isloye 2 multiply kiya and uska wt se toh karna hi hai 

Now we assume graph as a tree like structure and we goes down to cal no of nodes in subtree


*/

ll n;

template<typename T>
class Graph{
    unordered_map<T, list<pair<T, ll> > >adj;

    public:

    void addEdge(T u, T v, ll w, bool birdir=true){
        adj[u].push_back({v, w});
        if(birdir){
            adj[v].push_back({u, w});
        }
    }

    ll getMaxDist(){
        unordered_map<T, bool>visited;
        vector<ll>ct(n, 0); // maintain no of nodes in subtree (including itself) for a particular node

        ll ans=0;

        function<ll(T)>dfs_helper;// cal nodes in substree of each nodes
        dfs_helper = [&](T src)->ll{
            visited[src]=true;
            ct[src] = 1;

            for(auto child: adj[src]){
                ll dx = child.second; //edge weight
                if(!visited[child.first]){
                    ct[src] += dfs_helper(child.first);
                    ll no_of_right_nodes = ct[child.first];
                    ll no_of_left_nodes = n-no_of_right_nodes;

                    ans += 2*(min(no_of_left_nodes, no_of_right_nodes))*dx;
                }
            }
            return ct[src];
        };

        dfs_helper(0);
        return ans;
    }

};

ll solve(){
    
    Graph<ll>g;
    cin>>n;

    for(ll i=1; i<n; i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g.addEdge(u-1, v-1, w);
    }

    return g.getMaxDist();
}

int main(){
    fstIO;

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t, tc=1;
    cin>>t;
    while(t--){
        cout<<"Case #"<<tc++<<": "<<solve()<<endl;
    }
    return 0;
}