// https://leetcode.com/discuss/interview-question/794840/Google-or-Software-Engineer-Internship-2021-or-Online-test-questions-(OA)
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
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

vector<int>adj[100005];

bool isCoprime(int a, int b){
    for(int i=2; i<= min(a,b); i++){
        if(a%i==0 and b%i==0)return false;
    }
    return true;
}

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);

    for(int i=0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>v, visited(n, 0);
    vector<int>ans(n, -1);

    function<void(int)>dfs_helper;
    dfs_helper = [&](int src){
        visited[src]=1;
        for(int i=v.size()-1; i>=0; i--){
            if(!isCoprime(arr[src], v[i])){
                ans[src]=v[i];
                break;
            }
        }
        v.push_back(arr[src]);
        for(int child: adj[src]){
            if(!visited[child]){
                dfs_helper(child);
            }
        }
        v.pop_back();
    };

    dfs_helper(0);
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<=n; i++){
        adj[i].clear();
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}