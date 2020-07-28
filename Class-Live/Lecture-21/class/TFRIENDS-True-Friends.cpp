#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007
#define MAX 105

ll n;
vector<int>order;
vector<int>adj[MAX], tranpose_adj[MAX];
bool visited[MAX]={false};

void DFS(int src){
    visited[src]=true;

    for(int child: adj[src]){
        if(!visited[child]){
            DFS(child);
        }
    }
    order.push_back(src);
}

void DFST(int src){
    visited[src]=true;

    for(int child: tranpose_adj[src]){
        if(!visited[child]){
            DFST(child);
        }
    }
}

void solve(){
    memset(visited, false, sizeof visited);

    for(int i=0; i<n; i++){
        if(!visited[i]){
            DFS(i);
        }
    }

    for(int i=0; i<=n; i++){
        visited[i]=false;
    }

    int ans=0;
    for(int i=n-1; i>=0; i--){
        if(!visited[order[i]]){
            DFST(order[i]);
            ans++;
        }
    }
    cout<<ans<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                char ch;
                cin>>ch;
                if(ch == 'Y'){
                    adj[i].push_back(j);
                    tranpose_adj[j].push_back(i);
                }
            }
        }

        solve();
        for(int i=0; i<=n; i++){
            adj[i].clear();
            tranpose_adj[i].clear();
        }
        order.clear();
    }
    return 0;
}