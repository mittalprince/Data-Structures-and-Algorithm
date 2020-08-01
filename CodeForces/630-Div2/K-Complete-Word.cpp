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
    ll totalComponent;
    public:

    DSU(int v){
        parent = vector<ll>(v);
        rank = vector<ll>(v, 0);

        for(int i=0; i<v; i++){
            parent[i]=i;
        }
    }

    ll get(ll a){
        if(parent[a] == a)return parent[a];
        return parent[a] = get(parent[a]);
    }

    void union_sets(ll a, ll b){
        a = get(a);
        b = get(b);

        if(parent[a] != parent[b]){
            if(rank[a]<rank[b])swap(a,b);
            parent[b]=a;
            if(rank[a]==rank[b]) rank[a]++;
            totalComponent--;
        }
    }
};

ll c[200005][26]; // maintain freq of each char for ith superparent/leader

void solve(){
    ll n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    DSU g(n);

    for(int i=0; i<n-k; i++){// for k-palindrone property
        g.union_sets(i, i+k);
    }

    for(int i=0; i<n/2; i++){// for palindrome property 
        g.union_sets(i, n-i-1);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<26; j++)
            c[i][j]=0;
    }

    for(int i=0; i<n; i++){ // jinte bhi index same parent se belong karta hai unke sabhi char ki freq store kar lee
        c[g.get(i)][s[i]-'a']++;
    }

    ll ans=0;
    for(int i=0; i<n; i++){
        if(i == g.get(i)){ // agr ith elemnt superparent hai toh
        // isme sabse jayda occur hone vale char ho same rakhenge and baki sabko yeh bna denge
            ll sum=0; // store total char freq for this parent
            ll max_occuring_char_freq=0; // store freq of max occuring char
            for(int j=0; j<26; j++){
                sum += c[i][j];
                max_occuring_char_freq = max(max_occuring_char_freq, c[i][j]);
            }
            ans += (sum-max_occuring_char_freq); // add their diff as we will make all other char to max_occuring_char
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