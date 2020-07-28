#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef unsigned long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

/*
Logic used: prefix sum

Here we first maintain the freq of ranges, the ranges which has high freq will be multipled with high value
so that the sum whill have max value.

For this we use prefix sum logic, and in last we sort the arr and freq both.
*/
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,q;
    cin>>n>>q;
    vector<ll> arr(n), freq(n, 0);
    ip(arr, n);

    for(int i=0; i<q; i++){
        int l,r;
        cin>>l>>r;
        freq[--l]++;
        if(r<n) freq[r]--;
    }

    for(int i=1; i<n; i++){
        freq[i] += freq[i-1];
    }

    sort(arr.begin(), arr.end());
    sort(freq.begin(), freq.end());

    ll ans=0;
    for(int i=0; i<n; i++){
        ans += (arr[i]*freq[i]);
    }
    cout<<ans<<endl;
    return 0;
}