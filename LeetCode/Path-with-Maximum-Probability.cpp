// https://leetcode.com/problems/path-with-maximum-probability/
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

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int,double> >adj[10005];

    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        double w = succProb[i];

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<double>dist(n, 0.0);
    vector<bool>visited(n, 0);

    priority_queue<pair<double, int> >pq;
    dist[start]=1;

    pq.push({1, start});
    while(!pq.empty()){
        pair<double, int> top = pq.top();
        pq.pop();

        if(visited[top.second])continue;
        visited[top.second]=true;

        for(auto child: adj[top.second]){
            if(!visited[child.first]){
                if(dist[child.first]<top.first*child.second){
                    dist[child.first] = dist[top.second]*child.second;
                    pq.push({dist[child.first], child.first});
                }
            }
        }
    }

    return dist[end];

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}