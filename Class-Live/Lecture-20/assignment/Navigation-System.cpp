#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define MOD 1000000007
#define MAX 200005

vector<ll>adj[MAX];

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n,m;
    cin>>n>>m;
    
    for(int i=0; i<m; i++){
        ll u,v;
        cin>>u>>v;
        adj[v].push_back(u); // use tranpose of graph
    }

    ll k;
    cin>>k;

    ll arr[k];
    ip(arr, k);

    vector<ll>dist(n+1, INT_MAX), diff_path_ct(n+1, 0);

    queue<pair<ll, ll> >q;
    q.push({0, arr[k-1]}); // treat dest as src now and BFS
    dist[arr[k-1]]=0;

    while(!q.empty()){
        pair<ll, ll>front = q.front();
        q.pop();

        for(ll child: adj[front.second]){
            if(dist[child]>dist[front.second]+1){
                dist[child] = dist[front.second]+1;
                diff_path_ct[child]=1;
                q.push({dist[child], child});
            }
            else if(dist[child] == dist[front.second]+1){
                diff_path_ct[child]++; // i.e we can reach the same child from diff src, so for this child we have 2 option to come
            }
        }
    }

    ll max_rebuild=0, min_rebuild=0;

    for(ll i=0; i<k-1; i++){
        if(dist[arr[i]]-1 < dist[arr[i+1]]){
            // now if we have two nodes u1, u2 and u1 comes before u2. so dist of u2 will be less than dist of u1.
            // so here we check the same thing.
            // if the dist of ith node -1 will be less than dist of i+1 node, (as if ith node is T dist far then i+1 will be T-1 dist far)
            //then it must bu possible only when i+1 node is not from Shortes path.
            // so here we rebuild both max and min
            max_rebuild++;
            min_rebuild++;
        }
        else if(diff_path_ct[arr[i]]>1){
            // if we have  or more option at this node such that using all these we can reach at dest, 
            // although not optimal but we can choose , so all time rebuild works.
            max_rebuild++;
        }
    }

    cout<<min_rebuild<<" "<<max_rebuild<<endl;
    return 0;
}