// https://codeforces.com/contest/134/problem/B
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

int ans=inf;

void minStep(int a, int b, int steps){
    if(a==1 and b==1){
        ans=min(ans, steps);
        return;
    }
    if(a-b>0)minStep(a-b, b, steps+1);
    if(b-a>0)minStep(a, b-a, steps+1);
}

void solve(){
    int n;
    cin>>n;
    if(n==1){
        cout<<0<<endl;
        return;
    }
    ans = inf;
    for(int i=1; i<n; i++){
        minStep(i, n-i, 1);
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