#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<list>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define MOD 1000000007
#define MAX 100005

/*
Logic: Used Multisrc BFS
we have total k product. So we find what will be the cost to bring kth product into all state.
AT last we need s product so we sort the cost arr and add first s min cost into ans for each state.
*/

ll n,m,k,s;
ll arr[MAX]; // store ith state produce which type of good prod
ll cost[MAX][105]; // cost[i][j] -> store the cost req to bring jth product into the ith state
vector<ll> adj[MAX]; // store roads

void solve(){
    memset(cost, -1, sizeof(cost));

    queue<ll>q;

    for(ll product=1; product<=k; product++){// check yeh product konsa state mein avaible hai
    // us state mein is product ko mangvane ki ocst 0 hogi so update it.
        for(ll i=1; i<=n; i++){
            if(arr[i] == product){
                cost[i][product]=0;
                //as in normal BFS we intially put the src vertex, but in this case we put all the src of jth product
                // into queue, this is the point where multisrc BFS used.
                // Now for each src we update their nearest stae product bring cost which is minimal
                q.push(i); // now this state into queue, as it provide the same prod to other state.
            }
        }
        while(!q.empty()){
            ll node = q.front();
            q.pop();

            for(ll child: adj[node]){
                if(cost[child][product] == -1){//here we check whether the in ith state product avaivle or not, if not we update the cost to bring the product 
                    cost[child][product] = cost[node][product]+1;
                    q.push(child);
                }
            }
        }
    }

    for(ll i=1; i<=n; i++){
        sort(cost[i]+1, cost[i]+k+1);
        ll ans = 0;
        for(ll j=1; j<=s; j++){
            ans += cost[i][j];
        }
        cout<<ans<<" ";
    }
    cout<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>m>>k>>s;

    ip(arr, n);

    for(ll i=0; i<m; i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    solve();
    return 0;
}