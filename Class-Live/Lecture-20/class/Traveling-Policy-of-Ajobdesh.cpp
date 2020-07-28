// Traveling Policy of Ajobdesh
#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<unordered_map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define MOD 1000000007
#define MAX 10005
#define inf 1000000000

ll n,r,c,q;
ll NodeSeCapital[MAX], CapitalSeNode[MAX];
unordered_map<ll, list<ll> >adj, transpose_adj;

void BFS(){
    
    for(ll i=0; i<n; i++){
        NodeSeCapital[i]=CapitalSeNode[i]=inf;
    }

    queue<ll>q;
    q.push(c);

    CapitalSeNode[c]=NodeSeCapital[c]=0;

    while(!q.empty()){
        ll front = q.front();
        q.pop();

        for(ll child: adj[front]){
            if(CapitalSeNode[child]>CapitalSeNode[front]+1){
                CapitalSeNode[child] = CapitalSeNode[front]+1;
                q.push(child);
            }
        }
        for(ll child: transpose_adj[front]){
            if(NodeSeCapital[child]>NodeSeCapital[front]+1){
                NodeSeCapital[child] = NodeSeCapital[front]+1;
                q.push(child);
            }
        }
    }
}   

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t,tc=1;
    cin>>t;
    while(t--){
        cout<<"Case "<<tc++<<":\n";
        cin>>n>>r>>c>>q;
        for(ll i=0; i<r; i++){
            ll u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            transpose_adj[v].push_back(u);
        }

        BFS();

        for(ll i=0; i<q; i++){
            ll u,v;
            cin>>u>>v;
            ll ans = NodeSeCapital[u]+CapitalSeNode[v];
            if(ans >= inf){
                cout<<"Not possible to go from "<<u<<" to "<<v<<"."<<endl;
            }
            else{
                cout<<"The shortest distance from "<<u<<" to "<<v<<" is "<<ans<<"."<<endl;
            }
        }

        adj.clear();
        transpose_adj.clear();
    }
    return 0;
}