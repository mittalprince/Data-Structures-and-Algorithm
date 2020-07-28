#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<functional>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007
#define MAX 200005

/*
Logic: Topological Sort, Tranpose of grpah.

In thi question the trick we have used is to construct the transpose of graph and then just perform
totplogical sort, but remember pick those node whose inDegree is 0 and it has higher index val as we have to find
smallest lexographical permutation.
So we pick nodes from pq and assign values to them start from n.
*/

ll n,m;
vector<ll> adj[MAX], inDegree(MAX, 0);
ll arr[MAX]={0};


void TopologicalSort(){
    priority_queue<ll>pq; 

    for(int i=1; i<=n; i++){
        if(inDegree[i] == 0){
            pq.push(i);
        }
    }

    ll val=n;
    while(!pq.empty()){
        ll top = pq.top();
        pq.pop();

        arr[top]=val;
        val--;

        for(ll child: adj[top]){
            inDegree[child]--;
            if(inDegree[child] == 0){
                pq.push(child);
            }
        }
    }

    for(ll i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>m;
    for(ll i=0; i<m; i++){
        ll u,v;
        cin>>u>>v;
        adj[v].push_back(u);
        inDegree[u]++;
    }
    
    TopologicalSort();
    return 0;
}

/*
Auto lets you declare a variable with particular type whereas decltype lets you extract the type 
from the variable so decltype is sort of an operator that evaluates the type of passed expression.
*/