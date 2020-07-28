#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    #endif

    vector<vector<int>> adj;
    bool visited[1005] = {0};

    int d,n;
    cin>>n>>d;

    int ans=INT_MAX;
    
    adj.resize(n);
    for(int i=0; i<d; i++){
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<1005; j++){
            visited[j]=false;
        }
        int ct=1;
        function<void(int)>bfs_helper;
        bfs_helper = [&](int src){
            visited[src]=true;
            for(int j=0; j<adj[src].size(); j++){
                if(!visited[adj[src][j]]){
                    ct++;
                    bfs_helper(adj[src][j]);
                }
            }
        };
        bfs_helper(i);
        ans = min(ans, ct);
    }
    cout<<ans<<endl;
    return 0;
}