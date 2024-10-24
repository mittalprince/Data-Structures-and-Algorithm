// #include<iostream>
// #include<vector>
// using namespace std;
// typedef long long ll;
// #define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
// #define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
// #define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
// #define MOD 1000000007

// class DSU{
//     vector<ll>parent, rank;

//     public:

//     DSU(ll n){
//         parent.resize(n+1);
//         rank.resize(n+1);
//         for(int i=0; i<=n; i++){
//             parent[i]=i;
//             rank[i]=i;
//         }
//     }

//     ll get(ll a){
//         if(parent[a] == a)return parent[a];
//         return parent[a] = get(parent[a]);
//     }

// 	ll getRank(ll a){
//         return rank[a];
//     }
	
//     void union_set(ll a, ll b){
//         a = get(a);
//         b = get(b);

// 		if(a != b){
//             if(rank[a]<rank[b]){
//                 swap(a, b);
//             }
//             parent[b]=a;
//         }
//     }
// };

// vector<int> solve(int nodes, int edges, vector<int> c_from, vector<int> c_to) {
// 	DSU g(nodes+1);
// 	vector<int>ans;
// 	for(int i=0; i<edges; i++){
// 		g.union_set(c_from[i], c_to[i]);
// 		ll max_strength=0;
// 		for(int j=1; j<=nodes; j++){
// 			if(g.get(j) == j){
// 				max_strength += g.getRank(j);
// 			}
// 		}
// 		ans.push_back(max_strength);
// 	}
// 	return ans;
// }

// int main(){

//     #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     #endif

//     int n;
//     cin>>n;
//     vector<int> arr(n);
    
//     return 0;
// }

// /*

// if(a != b){
// 	if(rank[a]<rank[b]){
// 		parent[a] = b;
// 		rank[a] = b;
// 	} else {
// 		parent[b] = a;
// 		rank[b] = a;
// 	}
// }
// */
#include<iostream>
#include<vector>
#include<algorithm>
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
    int n;
    cin>>n;
    string s;
    cin>>s;
    // bool f=0;
    // for(int i=0; i<n; i++){
    //     if(s[i]=='"')f = !f;
    //     else if(s[i]==',' && !f) s[i]='.';
    // }
    cout<<s<<endl;
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