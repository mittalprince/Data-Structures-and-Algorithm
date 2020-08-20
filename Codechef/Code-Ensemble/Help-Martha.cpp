// https://www.codechef.com/CENS2020/problems/CENS20G
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

void solve(){
    string s;
    cin>>s;
    ll left=0, right=0, down=0, top=0;
    
    for(char i: s){
        if(i=='R')right++;
        else if(i=='L')left++;
        else if(i=='U')top++;
        else down++;
    }
    ll x,y;
    cin>>x>>y;
    
    ll q;
    cin>>q;
    for(ll i=0; i<q; i++){
        ll a,b;
        cin>>a>>b;
        ll x_diff = a-x;
        ll y_diff = b-y;

        if(x_diff <= right and x_diff >= (-left) and y_diff<=top and y_diff >= (-down)){
            cout<<"YES "<<abs(x_diff)+abs(y_diff)<<endl;
        }
        else cout<<"NO\n";
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    fstIO;
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}