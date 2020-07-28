// https://codeforces.com/contest/1374/problem/D
#include<iostream>
#include<vector>
#include<map>
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
    ll n,k;
    cin>>n>>k;

    ll arr[n];
    vector<ll>v;

    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(arr[i]%k){
            v.push_back(k-(arr[i]%k));
        }
    }
    sort(v.begin(), v.end());
    ll ans=0;
    map<ll, ll>m; // store ki agr itna remainder hai toh usko k se divisible karne ke liye kitne operation lagenge 

    for(int i=0; i<v.size(); i++){
        if(m[v[i]%k]){
            m[v[i]%k]+=k; // else we just add k into it as we already consider this remainder by adding some val to make it divisible by k
        }
        else m[v[i]%k] = v[i]; // if this remainder occur first time then we need to add v[i] to arr[i]
        ans = max(ans, m[v[i]%k]); // at each step we check ki ek particular remainder ko divislbe banane ke liye kitna max operation lagenge
    }
    if(ans)ans++; // since we make x=0 to x=1, but we req to update only when there is atleast a sigle no which is not diivislbe by k, int this case ans always exist
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
