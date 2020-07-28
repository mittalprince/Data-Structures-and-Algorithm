#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

class DSU{
    vector<ll>parent, rank;
    ll totalComponents;

    public:

    DSU(ll n){
        totalComponents = n;
        parent.resize(n);
        rank.resize(n);

        for(int i=0; i<n; i++){
            parent[i]=i;rank[i]=0;
        }
    }

    ll get(ll a){
        if(parent[a] == a)return parent[a];
        parent[a] = get(parent[a]);
    }

    void union_set(ll a, ll b){
        a = get(a);
        b = get(b);

        if(a != b){
            if(rank[a]<rank[b]){
                swap(a, b);
            }
            parent[b]=a;
            if(rank[a]==rank[b])rank[a]++;
            totalComponents--;
        }
    }

    
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}