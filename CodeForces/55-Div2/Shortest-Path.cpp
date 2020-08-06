// https://codeforces.com/contest/59/problem/E
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
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
#define MAX 3005
#define ppi pair<ll, ll> 
#define pii pair<ppi, ll>

ll n,m,k;
vector<ll>adj[MAX];
map<pii, bool>forbid;
vector<vector<bool> >visited(MAX, vector<bool>(MAX, false));
ppi dp[MAX][MAX];

ppi BFS(){
    queue<ppi>q;
    visited[1][1]=true;
    q.push({1,1});

    while(!q.empty()){
        ppi front = q.front();
        q.pop();
        if(front.second == n){
            return front;
        }
        for(ll i: adj[front.second]){
            if(!visited[front.second][i] and  !forbid[{front, i}]){
                visited[front.second][i]=true;
                dp[front.second][i]=front;
                q.push({front.second, i});
            }
        }
    }
    return {-1,-1};
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>m>>k;
    
    for(int i=0; i<m; i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0; i<k; i++){
        ll a,b,c;
        cin>>a>>b>>c;
        forbid[{{a,b},c}]=true;
    }

    ppi last = BFS();
    if(last == make_pair((ll)-1, (ll)-1)){
        cout<<"-1\n";
        return 0;
    }
    
    ll size=0;
    vector<ll>path;
    for(ppi z=last; z!= make_pair((ll)1, (ll)1); z=dp[z.first][z.second]){
        size++;
        path.push_back(z.second);
    }
    
    path.push_back(1);
    cout<<size<<endl;
    reverse(path.begin(), path.end());
    for(ll i:path){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}