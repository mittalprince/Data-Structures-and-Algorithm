#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007
#define INF 1e15;

const long long mod = 1000000007;
// const long long INF = 1e15;
int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<long long, long long>>>adj(n);
    for(auto it: roads){
        adj[it[0]].push_back({ it[1], it[2]});
        adj[it[1]].push_back({ it[0], it[2]});
    }
    priority_queue<pair<long, long>>pq;
    vector<long long>dp(n+1,0), dist(n+1, INF);

    pq.push({ 0, 0}); // {distance, node}
    dist[0]=0;
    dp[0]=1;
    while(!pq.empty()){
        pair<long long, long long>front = pq.top();
        pq.pop();

        long long node = front.second;
        long long node_dist = -front.first;

        for(auto child: adj[node]){
            long long edge_dist = child.second;
            if(dist[child.first]>node_dist+edge_dist){
                dist[child.first] = node_dist+edge_dist;
                dp[child.first] = dp[node];
                pq.push({ -dist[child.first], child.first });
            } else if(dist[child.first] == node_dist+edge_dist){
                dp[child.first] = (dp[child.first]+dp[node])%mod;
            }
        }
    }
    return dp[n-1];
}

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}