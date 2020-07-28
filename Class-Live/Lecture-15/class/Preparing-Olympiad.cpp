#include<iostream>
#include<vector>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n,x,l,r;
ll *arr;

ll solve(){
    ll ans=0;

    for(int i=2; i<(1<<n); i++){
        ll mi=LLONG_MAX, mx=LLONG_MIN, sum=0;
        for(int j=0; j<n; j++){
            if(i&(1<<j)){
                sum += arr[j];
                mi = min(mi, arr[j]);
                mx = max(mx, arr[j]);
            }
        }
        if(sum>=l && sum<=r && (mx-mi)>=x){
            ans++;
        }
    }
    return ans;
}
int main(){
    cin>>n>>l>>r>>x;
    arr = new ll[n];
    ip(arr, n);
    cout<<solve()<<endl;
    return 0;
}