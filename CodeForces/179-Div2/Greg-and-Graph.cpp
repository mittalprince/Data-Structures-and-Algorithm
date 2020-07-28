#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
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
#define MAX 505

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    
    ll adj[MAX][MAX];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>adj[i][j];
        }
    }
    ll seq[MAX], ans[MAX]={0};
    for(int i=1; i<=n; i++){
        cin>>seq[i];
    }
    
    reverse(seq+1, seq+n+1);

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                adj[i][j] = min(adj[i][j], adj[i][seq[k]]+adj[seq[k]][j]);
            }
        }

        for(int i=1; i<=k; i++){
            for(int j=1; j<=k; j++){
                ans[k] += adj[seq[i]][seq[j]];
            }
        }
    }
    for(int i=n; i>=1; i--){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}