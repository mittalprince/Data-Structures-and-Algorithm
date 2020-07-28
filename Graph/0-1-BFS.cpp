// 0-1 BFS
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<list>
#include<climits>
#include<unordered_map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define MOD 1000000007
#define ppi pair<ll, ll>

ll m;
unordered_map<ll, list<ppi> > adj;

void BFS_0_1(ll src){
    unordered_map<ll, ll>dist;

    for(auto node: adj){
        dist[node.first]=INT_MAX;
    }  

    deque<ll>q;
    q.push_back(src);

    dist[src]=0;

    while(!q.empty()){
        ll front = q.front();
        q.pop_front();

        for(auto child: adj[front]){
            if(dist[child.first] == INT_MAX){
                ll edge_dist = child.second;
                dist[child.first] = dist[front]+edge_dist;
                if(edge_dist) q.push_back(child.first);
                else q.push_front(child.first);
            }
        }
    }

    for(auto node: adj){
        cout<<"Distnace of "<<node.first<<" from "<<src<<" is "<<dist[node.first]<<endl;
    }
    
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>m;
	for(ll i = 0 ; i < m ; i++){
		ll u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	BFS_0_1(0);

    return 0;
}

/*
7
0 1 0
1 2 1
0 3 1
2 3 1
2 4 1
3 4 0
4 5 1

Distnace of 5 from 0 is 2
Distnace of 4 from 0 is 1
Distnace of 3 from 0 is 1
Distnace of 2 from 0 is 1
Distnace of 1 from 0 is 0
Distnace of 0 from 0 is 0

*/