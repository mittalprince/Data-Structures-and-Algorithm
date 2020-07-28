#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

void solve(){
    vector<int>adj[20];
    int v,e;
    cin>>v>>e;

    for(int i=0; i<e; i++){
        int U,V;
        cin>>U>>V;
        adj[U].push_back(V);
    }

    bool visited[20]={false};
    
    int src, dest;
    cin>>src>>dest;

    queue<int>q;
    q.push(src);
    int ans=0;

    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        if(front == dest){
            ans++;
            continue;
        }
        visited[front]=true;
        for(int i: adj[front]){
            if(!visited[i]){
                q.push(i);
            }
        }
    }
    cout<<ans<<endl;
}

int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}   