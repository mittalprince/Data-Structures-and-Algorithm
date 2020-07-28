#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<functional>
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
Logic: Used Topological Sort

Here we approach greedy means first we finish all independent task that can be run on main processor,
then we interchange our queue means switch to coprocessor and then we run all independent task on this.

This process will continue untill we have considered all task.
*/

ll n,m;
vector<ll>adj[MAX], inDegree(MAX, 0);
bool arr[MAX]={false};

void TopologicalSort(){
    queue<ll>q[2];

    for(ll i=0; i<n; i++){
        if(inDegree[i]==0){
            q[arr[i]].push(i);
        }
    }

    ll min_processor_req=0;

    while(!q[0].empty() || !q[1].empty()){
        while(!q[0].empty()){
            ll front = q[0].front();
            q[0].pop();

            for(ll child: adj[front]){
                inDegree[child]--;
                if(inDegree[child]==0){
                    q[arr[child]].push(child);
                }
            }
        }

        min_processor_req += (!q[1].empty()); // if we swtich to coprocssor then we check if we need any coprocssor
        // or not if yes then increment min_procssor_req

        while(!q[1].empty()){
            ll front = q[1].front();
            q[1].pop();

            for(ll child: adj[front]){
                inDegree[child]--;
                if(inDegree[child]==0){
                    q[arr[child]].push(child);
                }
            }
        }
    }
    
    cout<<min_processor_req<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>m;
    ip(arr, n);

    for(ll i=0; i<m; i++){
        ll u,v;
        cin>>u>>v;
        adj[v].push_back(u);
        inDegree[u]++;
    }

    TopologicalSort();
    return 0;
}