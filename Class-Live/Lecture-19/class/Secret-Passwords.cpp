// Secret Passwords
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

ll n;
string arr[200005];

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

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    DSU g(26);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        for(int j=0; j<arr[i].length()-1; j++){
            g.union_sets(arr[i][j]-'a', arr[i][j+1]-'a');
            //make set of adjacent char so what when they appear in other string they point to same superprarent
        }
    }
    
    bool ct[26]={0}; // as atmost 26 superparent can exist
    for(int i=0; i<n; i++){
        for(int j=0; j<arr[i].length(); j++){
            ct[g.get(arr[i][j]-'a')]=true; // now for each char of each string, increment ct of its superparent
        }
    }
    int ans=0;

    for(int i=0; i<26; i++){
        if(ct[i]) ans++;
    }

    cout<<ans<<endl;
    return 0;
}
