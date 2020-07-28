// https://zhuhan0.blogspot.com/2017/07/leetcode-261-graph-valid-tree.html
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
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

bool validTree(int n, vector<vector<int>>&edges){
    if(edges.empty())return n==1;

    unordered_map<int, vector<int> >adj;
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    queue<int>q;
    unordered_map<int, int>parent;
    unordered_map<int, bool>visited;

    q.push(0);
    visited[0]=true;
    parent[0]=0;

    while(q.empty()){
        int top = q.front();
        q.pop();

        for(int child: adj[top]){
            if(!visited[child]){
                parent[child]=top;
                visited[child]=true;
                q.push(child);
            }
            else if(parent[top] != child)return false; // cycle detect
        }
    }

    for(int i=0; i<n; i++){
        if(!visited[i])return false; // unconnected node found;
    }

    return true;
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