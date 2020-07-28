// K-Complete Word
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

ll c[200005][26]; // maintain freq of each char for ith superparent/leader

class DSU{
    vector<ll> parent, rank;
    ll totalComponents;
    public:

    DSU(ll n){
        totalComponents = n;
        parent = vector<ll>(n);
        rank = vector<ll>(n);

        for(int i=0; i<n; i++){
            parent[i]=i;
            rank[i]=0;
        }
    }

    ll get(ll a){
        if(parent[a] == a){
            return parent[a];
        }

        return parent[a] = get(parent[a]);
    }

    void union_sets(ll a, ll b){
        a = get(a); // get parent of a
        b = get(b); // get parent of b
 
        if(a!=b){// if both are not in same set then combine them
            if(rank[a]<rank[b]){
                swap(a, b);
            }
            parent[b]=a;
            if(rank[a]==rank[b]) rank[a]++;
            totalComponents--;
        }
    }
};

void solve(){
    ll n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    DSU g(n);

    for(int i=0; i<n/2; i++){
        g.union_sets(i, n-i-1); // add palindrome property 
    }

    for(int i=0; i<n-k; i++){
        g.union_sets(i, i+k); // add k-palindrone property
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<26; j++){
            c[i][j]=0;
        }
    }

    for(int i=0; i<n; i++){
        c[g.get(i)][s[i]-'a']++;
    }

    ll ans=0;
    for(int i=0; i<n; i++){
        if(i==g.get(i)){ // if ith element is superparent
            ll sum=0; 
            ll max_occuring_char=0;
            for(int j=0; j<26; j++){
                sum += c[i][j];
                max_occuring_char = max(max_occuring_char, c[i][j]);
            }
            ans += (sum-max_occuring_char);
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