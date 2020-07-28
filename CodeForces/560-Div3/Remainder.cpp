// https://codeforces.com/contest/1165/problem/A
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

     int n, x, y;
    cin >> n >> x >> y;
    string num;
    cin >> num;
 
    reverse(num.begin(), num.end());
    int ans = 0;
 
    if ( num[y] == '0' ) ans++;
    for ( int i = x - 1; i>= 0; i-- ) {
        if ( i == y ) continue;
        if ( num[i] == '1' ) ans++;
    }
 
    cout << ans << endl;
    
    return 0;
}