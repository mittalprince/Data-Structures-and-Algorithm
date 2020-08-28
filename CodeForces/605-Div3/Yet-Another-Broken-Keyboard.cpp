// https://codeforces.com/contest/1272/problem/C
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
    int n,k;
    cin>>n>>k;

    string s;
    cin>>s;
    bool freq[26]={0};

    for(int i=0; i<k; i++){
        char ch;
        cin>>ch;
        freq[ch-'a']=true;
    }

    ll ans=0, ct=0;
    for(int i=0; i<n; i++){
        if(freq[s[i]-'a']){
            ct++;
        }
        else{
            ans += ct*(ct+1)/2;
            ct=0;
        }
    }
    ans += ct*(ct+1)/2;

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