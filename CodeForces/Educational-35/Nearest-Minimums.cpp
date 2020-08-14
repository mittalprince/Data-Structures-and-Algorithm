// https://codeforces.com/contest/911/problem/A
#include<iostream>
#include<vector>
#include<unordered_map>
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

    int ans=inf;
    unordered_map<int, int>m;
    int min1=inf, min2=inf;

    for(int i=0; i<n; i++){
        int x; cin>>x;
        if(m.count(x)){
            int gap = i-m[x];
            if(x<min1){
                min1=x;
                min2=gap;
            }
            else if(x==min1){
                min2 = min(min2, gap);
            }
        }
        m[x]=i;
    }
    cout<<min2<<endl;
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