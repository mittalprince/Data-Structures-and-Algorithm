// https://www.codechef.com/problems/KRYP6
#include<iostream>
#include<vector>
#include<set>
#include<iterator>
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
    set<ll>s;
    for(int i=0; i<n; i++){
        ll x; cin>>x;
        set<ll>::iterator it = s.lower_bound(x);
        if(it == s.begin()){
            cout<<"-1\n";
        }
        else{
            cout<<*(--it)<<endl;
        }
        s.insert(x);
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