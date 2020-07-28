// https://codeforces.com/contest/785/problem/B
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

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,l,r,m;
    cin>>n;
    int opt1_max=0, opt1_min=inf;
    for(int i=0; i<n; i++){
        cin>>l>>r;
        opt1_max = max(opt1_max, l);
        opt1_min = min(opt1_min, r);
    }
    cin>>m;
    int opt2_max=0, opt2_min=inf;
    for(int i=0; i<m; i++){
        cin>>l>>r;
        opt2_max = max(opt2_max, l);
        opt2_min = min(opt2_min, r);
    }

    int ans=0;
    ans = max(ans, max(opt2_max-opt1_min, opt1_max-opt2_min));
    cout<<ans<<endl;
    return 0;
}