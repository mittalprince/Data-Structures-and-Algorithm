// https://codeforces.com/contest/1009/problem/D
#include<iostream>
#include<vector>
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

ll gcd(ll a, ll b){
    if(b==0)return a;
    return gcd(b, a%b);
}

void solve(){
    int n,m;
    cin>>n>>m;

    if(m<n-1){ // as grpah m,ust be connected without cycle so there must be alteast n-1 edges
        cout<<"Impossible\n";
        return;
    }

    vector<pair<ll,ll> >edges;
    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++){
            if(edges.size()==m)break;
            if(gcd(i,j)==1){
                edges.push_back({j,i});
            }
        }
    }
    if(edges.size() < m){
        cout<<"Impossible\n";
        return;
    }

    cout<<"Possible\n";
    for(auto it: edges){
        cout<<it.first<<" "<<it.second<<endl;
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}