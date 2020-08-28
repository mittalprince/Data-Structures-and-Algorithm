// https://codeforces.com/contest/1263/problem/D
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

    public:
    DSU(ll n){
        parent.resize(n), rank.resize(n);
        for(int i=0; i<n; i++){
            parent[i]=i;
            rank[i]=1;
        }
    }

    ll find(ll a){
        if(a == parent[a])return a;
        return parent[a] = find(parent[a]);
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
        }
    }
};

void solve(){
    int n;
    cin>>n;
    vector<string>arr(n);

    DSU g(26);

    // First make possible merge of all character of a string
    for(int i=0; i<n; i++){
        cin>>arr[i];
        for(int j=0; j<arr[i].length()-1; j++){
            g.merge(arr[i][j]-'a', arr[i][j+1]-'a');
        }
    }    

    // after merging we can know whether two string are equivalent or not, by using their superparent
    bool cnt[26]={0};
    for(int i=0; i<n; i++){
        for(int j=0; j<arr[i].length(); j++){
            // now for each char of each string mark the superparent
            cnt[g.find(arr[i][j]-'a')]=true;
        }
    }

    // total differnet subparent are ans string that have common subparent are equivalent to each other
    
    int ans=0;
    // total different supperent are minimum possible try
    for(int i=0; i<26; i++)ans += cnt[i];

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