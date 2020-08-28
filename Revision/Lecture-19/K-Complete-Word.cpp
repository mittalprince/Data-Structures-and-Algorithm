// https://codeforces.com/contest/1332/problem/C
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

class DSU{
    vector<ll>parent, rank;
    ll totalComponents, V;

    public:
    DSU(ll v){
        parent.resize(v), rank.resize(v);
        totalComponents=V=v;

        for(int i=0; i<v; i++){
            parent[i]=i;
            rank[i]=1;
        }
    }

    ll find(ll a){
        if(a == parent[a])return a;
        return parent[a]=find(parent[a]);
    }

    void merge(ll a, ll b){
        a = find(a);
        b = find(b);

        if(a!=b){
            if(rank[a]<rank[b]){
                swap(a,b);
            }
            parent[b]=a;
            if(rank[a]==rank[b])rank[a]++;
            totalComponents--;
        }
    }
};

ll c[200005][26];

void solve(){
    ll n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    DSU g(n);

    for(int i=0; i<n/2; i++){
        g.merge(i, n-i-1);
    }

    for(int i=0; i<n-k; i++){
        g.merge(i, i+k);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<26; j++){
            c[i][j]=0;
        }
    }

    for(int i=0; i<n; i++){
        c[g.find(i)][s[i]-'a']++;
    }

    ll ans=0;
    for(int i=0; i<n; i++){
        if(i==g.find(i)){
            ll sum=0; 
            ll max_occuring_char_freq=0; 
            for(int j=0; j<26; j++){
                sum += c[i][j];
                max_occuring_char_freq = max(max_occuring_char_freq, c[i][j]);
            }
            ans += sum-max_occuring_char_freq;
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
        solve();
    }
    return 0;
}