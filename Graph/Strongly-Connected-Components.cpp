#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007
#define MAX 100005

/*
A directed graph is strongly connected if there is a path between all pairs of vertices. 
A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph.
*/

bool visited[MAX]={false};
vector<ll>order;
vector<ll>ans[MAX];
vector<ll>adj[MAX], tranpose_adj[MAX];
ll n;

void DFS(ll src){
    visited[src]=true;

    for(ll child: adj[src]){
        if(!visited[child]){
            DFS(child);
        }
    }
    order.push_back(src);
}

void DFST(ll src, ll comp_no){
    visited[src]=true;
    ans[comp_no].push_back(src);

    for(ll child: tranpose_adj[src]){
        if(!visited[child]){
            DFST(child, comp_no);
        }
    }
}
void SCC(){
    memset(visited, false, sizeof(visited));

    for(ll i=1; i<=n; i++){
        if(!visited[i]){
            DFS(i);
        }
    }

    memset(visited, false, sizeof(visited));
    ll comp_no=1;
    for(ll i=n-1; i>=0; i--){
        if(!visited[order[i]]){
            DFST(order[i], comp_no);
            comp_no++;
        }
    }

    for(ll i = 1 ; i < comp_no ; i++){
		cout<<i<<"-->";
		for(auto node:ans[i]){
			cout<<node<<" ";
		}
		cout<<endl;
	}
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n;
    int m;
    cin>>m;

    for(ll i = 0 ; i < m ; i++){
		ll u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		tranpose_adj[v].push_back(u);
	}
    
    SCC();
    return 0;
}

/*
6 7
1 2
2 3
3 1
3 4
4 5
5 6
6 4

1-->1 3 2 
2-->4 6 5 
*/