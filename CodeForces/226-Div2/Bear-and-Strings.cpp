// https://codeforces.com/contest/385/problem/B
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

bool check(string s, int i){
    return (s[i]=='r' and s[i-1]=='a' and s[i-2]=='e' and s[i-3]=='b');
}

void solve(){
    string s;
    cin>>s;

    int n=s.length();
    ll ans=0;
    int start=0;
    for(int i=3; i<n; i++){
        if(check(s, i)){
            ans += (n-i)*((i-3)-start+1);
            start = i-2; //as we can start new substring fron "ear"
        }   
    }

    cout<<ans<<endl;
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