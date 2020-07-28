#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 1000005

ll sum[MAX]={0};
string a;
ll k;

void solve(){
    sum[0]=1;
    ll s=0;
    ll ans=0;

    for(ll i=0; i<a.length(); i++){
        s += a[i]-'0';
        if(s>=k) ans += sum[s-k];
        sum[s]++;
    }
    cout<<ans<<endl;
}
int main(){
    cin>>k;
    cin>>a;
    solve();
    return 0;
}