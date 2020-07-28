// https://codeforces.com/contest/1382/problem/A
#include<iostream>
#include<vector>
#include<unordered_map>
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
    int n1,n2;
    cin>>n1>>n2;

    unordered_map<ll ,bool> m;
    for(int i=0; i<n1; i++){
        int a;
        cin>>a;
        m[a]=true;
    }

    bool exist=false;
    ll ans;

    for(int j=0; j<n2; j++){
        int a;
        cin>>a;
        if(m.find(a) != m.end() and !exist){
            exist=true;
            ans = a;
        }
    }
    if(exist){
        cout<<"YES\n";
        cout<<"1 "<<ans<<endl;
        return;
    }
    cout<<"NO\n";
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