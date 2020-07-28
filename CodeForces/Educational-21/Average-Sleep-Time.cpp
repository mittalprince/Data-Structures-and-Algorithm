// https://codeforces.com/contest/808/problem/B
#include<iostream>
#include<vector>
#include<iomanip>
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

    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    ip(arr, n);

    ll total=0;
    ll sum=0;
    for(int i=0; i<k; i++){
        sum += arr[i];
    }
    total+= sum;

    for(int i=k; i<n; i++){
        sum += (arr[i]-arr[i-k]);
        total += sum;
    }
    ll denominator = n-k+1;
    double ans = (double)total/(double)denominator;
    cout<<fixed<<setprecision(10)<<ans<<endl;
    return 0;
}