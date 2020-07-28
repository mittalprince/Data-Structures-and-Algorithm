#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100005

ll dp[MAX];
vector<ll> graph[MAX];
ll n,m;

ll solve(ll src){
    if(src>n) return 0;

    if(dp[src] != -1) return dp[src];

    ll ans=0;
    for(ll i=0; i<graph[src].size(); i++){
        ans = max(ans, solve(graph[src][i])+1);
    }
    dp[src]=ans;
    return dp[src];
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        ll x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    }

    memset(dp, -1, sizeof(dp));
    ll ans=0;
    for(int i=1; i<=n; i++){
        ans = max(ans, solve(i));
    }
    cout<<(ans)<<endl;
    
    return 0;
}