// https://codeforces.com/contest/1392/problem/D
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
    ll n;
    cin>>n;
    string s;
    cin>>s;

    vector<int>pos;

    for(int i=0; i<n; ){
        int j=i;
        char ch=s[i];
        int ct=0;
        while(j<n and ch == s[j]){
            j++;
            ct++;
        }
        i=j;
        pos.push_back(ct);
    }

    if(pos.size()==1){
        cout<<(n+2)/3<<endl;
        return;
    }
    if(s[0] == s.back()){
        pos[0] += pos.back();
        pos.pop_back();
    }

    ll ans=0;
    for(int i: pos){
        ans += i/3;
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
        solve();
    }
    return 0;
}