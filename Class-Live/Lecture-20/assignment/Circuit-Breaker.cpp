#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define MOD 1000000007
#define MAX 1005

int adj[MAX][MAX]={0};

int v,e;

bool DFS(){
    vector<bool>visited(v, false);

    int ans=0;

    function<void(int,int,int)>dfs_helper;
    dfs_helper = [&](int start, int vertex, int len){
        visited[vertex]=true; // mark curr vertex as visited

        if(len==0){
            // check whether there is an edge from last vertex to start vertex
            visited[vertex]=false;
            if(adj[vertex][start]){// is an edge incremnt ans
                ans++;
            }
            return;
        }

        for(int i=0; i<v; i++){
            if(!visited[i] && adj[vertex][i]){// if not visited and an edge
            // apply dfs by decreasing len of path by 1
                dfs_helper(start, i, len-1);
            }
        }
        visited[vertex]=false;// backatracking park, unmarked it to use again in further dfs call
    };  
    
    // Every possible path of length (n-1) can be searched using only V – (n – 1) vertices (where V is the total number of vertices).
    for(int i=0; i<v-2; i++){
        dfs_helper(i, i, 2);
        // check all possible path of len n-1 (n=3)
        // here we check le len n-1 istead of n beacuse the last edge is from last vertex to starting vertex.
        // so when n-1 become 0 we check whether there is an edge from last vertex to start vertex.
        visited[i]=true; // mark curr vertex as visited as we have consider all cycle start with this vertex.
        if(ans>=1)return true;
    }

    return false;
}

bool solve(){
    
    cin>>v>>e;

    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }

    if(v<3) return true;

    bool isCyclePresent = DFS();
    if(isCyclePresent){
        // debug("cycle");
        int ct = 3*v-6;
        return(e<=ct);
    }
    else{
        // debug("no cycle")
        int ct = 2*v-4;
        return (e<=ct);
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
        cout<<"Case "<<tc++<<": ";
        if(solve()){
            cout<<"No\n";
        }
        else cout<<"Yes\n";
    }
    return 0;
}