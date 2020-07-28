#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<iomanip>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve(){
    ll n,l;
    cin>>n>>l;
    ll arr[n];
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    double opt1 = arr[0]-0;
    double opt3 = l - arr[n - 1];
    ll diff = 0;
    for(ll i=1; i<n; i++){
        diff = max(diff, arr[i]-arr[i-1]);
    }
    double opt2 = (double)diff/(double)2;
    double ans = (double)max(opt1, max(opt2, opt3));
    cout<<setprecision(10);
    cout<<(double)ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
