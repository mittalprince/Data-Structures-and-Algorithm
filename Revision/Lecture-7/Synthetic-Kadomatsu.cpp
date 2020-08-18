// https://atcoder.jp/contests/abc119/tasks/abc119_c
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

int n,a,b,c;
int *arr;

ll findMinCost(int i, ll sum_a, ll sum_b, ll sum_c){
    if(i==n){
        if(!sum_a or !sum_b or !sum_c)return inf;
        return abs(a-sum_a) + abs(b-sum_b) + abs(c-sum_c);
    }

    ll ans = inf;
    ans = min(ans, findMinCost(i+1, sum_a, sum_b, sum_c));
    ans = min(ans, findMinCost(i+1, sum_a+arr[i], sum_b, sum_c)+(sum_a?10:0));
    ans = min(ans, findMinCost(i+1, sum_a, sum_b+arr[i], sum_c)+(sum_b?10:0));
    ans = min(ans, findMinCost(i+1, sum_a, sum_b, sum_c+arr[i])+(sum_c?10:0));

    return ans;
}

void solve(){
    cin>>n>>a>>b>>c;
    arr = new int[n];
    ip(arr, n);
    ll ans = findMinCost(0,0,0,0);
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