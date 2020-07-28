#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define MOD 1000000007
const int V=5;

void DFS(bool graph[][V], bool marked[], int n, int vertex, int start, int &ans){
    marked[vertex]=true; // makr curr vertex true

    if(n==0){
        // check whether there is an edge from last vertex to start vertex
        marked[vertex]=false;
        if(graph[vertex][start]){ // is an edge incremnt ans
            ans++;
        }
        return;
    }
    
    for(int i=0; i<V; i++){
        if(!marked[i] && graph[vertex][i]){ // if not visited and an edge
        // apply dfs bu decreasing len of path by 1
            DFS(graph, marked, n-1, i, start, ans);
        }
    }
    marked[vertex]=false; // backatracking park, unmarked it to use again in further dfs call
}

int countCycles(bool graph[][V], int n){
    bool marked[V];
    memset(marked, false, sizeof(marked));

    int ans=0;
    for(int i=0; i<V-(n-1); i++){
        DFS(graph, marked, n-1, i, i, ans); // check all possible path of len n-1
        // here we check le len n-1 istead of n beacuse the last edge is from last vertex to starting vertex.
        // so when n-1 become 0 we check whether there is an edge from last vertex to start vertex.
        marked[i]=true; // marked true to ith vertex so that it never visit again
    }
    return ans/2; // since cycle is present so each vertex has two options, so divides by 2
}

int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    bool graph[][V] = {{0, 1, 0, 1, 0}, 
                      {1, 0, 1, 0, 1}, 
                      {0, 1, 0, 1, 0}, 
                      {1, 0, 1, 0, 1}, 
                      {0, 1, 0, 1, 0}}; 
    int n = 4; 
    cout<<"Total cycles of length "<<n<<" are "<<countCycles(graph, n)<<endl; 
    return 0; 

}