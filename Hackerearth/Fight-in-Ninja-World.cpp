#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
#define MAX 200005

ll solve(){
    ll edges;
    cin>>edges;
    vector<int>adj[MAX], level(MAX, -1);  
    set<ll>s;

    for(int i=0; i<edges; i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        s.insert(u);
    }

    queue<ll>q;
    ll ans=0;

    for(auto it: s){
        if(level[it]!= -1) continue;
        ll even=0, odd=0;

        q.push(it);
        level[it]=0;
        even++;

        while(!q.empty()){
            ll top = q.front();
            q.pop();

            for(ll i=0; i<adj[top].size(); i++){
                if(level[adj[top][i]] == -1){
                    level[adj[top][i]] = level[top]+1;
                    q.push(adj[top][i]);
                    if(level[adj[top][i]]&1)odd++;
                    else even++;
                };
            }
        }
        ans += max(even, odd);
    }
    return ans;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    #endif

    int t, tc=1;
    cin>>t;
    while(t--){
        cout<<"Case "<<tc++<<": "<<solve()<<endl;
    }
    return 0;
}