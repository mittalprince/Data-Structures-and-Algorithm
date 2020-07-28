// https://www.codechef.com/COOK120B/problems/PATHETIC
#include<iostream>
#include<vector>
#include<queue>
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
#define MAX 2e18

ll x=1,y=1;
vector<ll>primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

void cal(){
    // cout<<primes.size()<<endl;
    // int i=primes.size()-1;
    for(int i=0; i<primes.size(); i++){
        if(i&1 or i==2)x*=primes[i];
        else y*=primes[i];
    }
}

void solve(){
    int n;
    cin>>n;
    
    vector<int>adj[n];
    for(int i=1; i<n; i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool>visited(n, false);
    vector<ll>ans(n);

    queue<pair<ll ,ll > >q;
    q.push({0,0});
    
    while(!q.empty()){
        pair<ll, ll>top =q.front();
        q.pop();

        if(top.second)ans[top.first] = x;
        else ans[top.first] = y;
        visited[top.first]=true;

        for(int child: adj[top.first]){
            if(!visited[child]){
                q.push({child, !top.second});
            }
        }
    }

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

    int t;
    cin>>t;
    cal();
    while(t--){
        solve();
    }
    return 0;
}