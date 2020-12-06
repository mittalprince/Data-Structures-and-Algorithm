#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
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

void solve(){
    int n;
    cin>>n;

    unordered_map<string, set<string> >adj;

    for(int i=0; i<n; i++){
        string u,v;
        cin>>u>>v;

        adj[v].insert(u); // here is an direct edge from father to child
    }

    int q;
    cin>>q;

    while(q--){
        string grandparent;
        cin>>grandparent;

        int ans=0;
        for(string child: adj[grandparent]){ // hre is an loop for his each child 
            ans += adj[child].size(); // then add count of his grandchild into ans
        }

        cout<<ans<<endl;
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

// Compplxity -> O(n*q);