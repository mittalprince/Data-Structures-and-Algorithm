// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

unordered_map<int ,list<pair<int, int> > >adj;

int minReorder(int n, vector<vector<int>>& connections) {
    for(auto it: connections){
        int u=it[0];
        int v=it[1];

        adj[u].push_back({v,1});
        adj[v].push_back({u,0});//tranpose ki cost 0 kr doo, qki abb hum 0 to all nodes 
        // ka path dekh rahe hai
    }

    vector<int>dist(n, INT_MAX);
    deque<int>q;
    q.push_front(0);
    dist[0]=0;

    while(!q.empty()){
        int front = q.front();
        q.pop_front();

        for(auto child: adj[front]){
            if(dist[child.first] == INT_MAX){
                int edge_dist = child.second;
                dist[child.first] = edge_dist;
                if(edge_dist){
                    q.push_back(child.first);
                }
                else q.push_front(child.first);
            }
        }
    }

    int ans=0;
    for(int i=0; i<n; i++){
        // cout<<dist[i]<<" ";
        ans += dist[i];
    }
    return ans;
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