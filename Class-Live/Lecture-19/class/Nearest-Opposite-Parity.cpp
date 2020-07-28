// Nearest Opposite Parity
#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

ll n;
ll arr[200005], ans[200005];

class Graph{
    unordered_map<ll, list<ll> >adj;

    public:

    void addEdge(ll u, ll v){
        adj[u].push_back(v);
    }

    void BFS(){

        queue<ll>q;

        for(int i=1; i<=n; i++){
            ans[i] = -1;

            ll left = i-arr[i];
            ll right = arr[i]+i;

            // set ans for those which has valid jumps
            if(left>=1 && ((arr[left]&1)^(arr[i]&1))){
                ans[i]=1;
            }
            if(right<=n && ((arr[right]&1)^(arr[i]&1))){
                ans[i]=1;
            }

            if(ans[i] == 1)q.push(i); //also push valid nodes as we use them to find dist of other invalid
        }

        while(!q.empty()){
            ll top = q.front();
            q.pop();

            for(ll child: adj[top]){
                if(ans[child] != -1) continue;
                ans[child] = ans[top]+1;
                q.push(child);
            }
        }
    }
};
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    Graph g;
    cin>>n;

    ip(arr, n);

    for(ll i=1; i<=n; i++){
        ll left = i-arr[i];
        ll right = arr[i]+i;

        // we make directed for those who dont follow condition
        // edge left->i, right->i
        if(left>=1 && ((arr[left]&1)==(arr[i]&1))){
            g.addEdge(left, i);
        }
        if(right<=n && ((arr[right]&1)==(arr[i]&1))){
            g.addEdge(right, i);
        }
    }

    g.BFS();

    for(int i=1; i<=n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}