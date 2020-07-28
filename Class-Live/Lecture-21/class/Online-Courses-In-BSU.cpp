#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define MOD 1000000007

ll n,k;
vector<ll> examdenahai;
unordered_map<ll, list<ll> >g;
vector<ll>ans;
bool isCyclic=false;
ll visited[100005]={0};


// here we basically used the same logic to detect cycle in directed graph but instad of using two diff vector visited and inSatck,
// we use the same, so for this purpose until the node is in stack we mark it as 1 and when we consider all its child withour encountr cycle,
// we mark it as 2. Initally all val is 0

void tps(ll src){
    if(visited[src]==2)return; // if already visited this node and all its child need to consider again as we have already pushed this node ans into ans vector.
    visited[src]=1; // for each new node set visited to 1 means we are visiting this node
    // it will remain 1 untill we have consider all its child after that we will make it 2 means now 
    // we have considered this node with all its child.

    // if while visiting any child we get visiting of child as 1 means we there is cycle as its child are still in out stack
    // so set isCylic var

    for(ll child: g[src]){
        if(visited[child] == 1){ // means this child is aleady in stack so cycle present 
            isCyclic=true;
            return;
        }
        tps(child); // otherwise make rec call
    }
    visited[src]=2; // now remnove this node from stack and mark it as visited completely
    ans.push_back(src);
}

void dsf(){
    for(auto node: examdenahai){
        tps(node);
        if(isCyclic)break;
    }

    if(isCyclic){
        cout<<"-1\n";
        return;
    }

    cout<<ans.size()<<endl;
    for(ll i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>k;
    for(ll i=0; i<k; i++){
        ll x;
        cin>>x;
        examdenahai.push_back(x);
    }

    for(ll u=1; u<=n; u++){
        ll m;
        cin>>m;
        if(m==0) continue;
        for(ll j=0; j<m; j++){
            ll v;
            cin>>v;
            g[u].push_back(v);
        }
    }
    dsf();
    return 0;
}