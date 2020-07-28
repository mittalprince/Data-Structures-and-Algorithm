// https://codeforces.com/contest/492/problem/C
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

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n,r,avg;
    cin>>n>>r>>avg;
    vector<pair<int, int> > arr(n);
    ll sum=0;
    for(int i=0; i<n; i++){
        cin>>arr[i].second>>arr[i].first;
        sum += arr[i].second;
    }
    ll max_marks = avg*n;
    ll ans=0;
    ll i=0;
    sort(arr.begin(), arr.end());
    while(sum<max_marks and i<n){
        ll t = min(max_marks-sum, r-arr[i].second);
        ans += t*arr[i].first;
        sum += t;
        i++;
    }
    cout<<ans<<endl;
    return 0;
}