// DCEPC11B - Boring Factorials
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n,p;

ll fstPower(ll a, ll b, ll m){
    ll ans=1;
    while(b){
        if(b&1){
            ans = (ans%m * a%m)%m;
        }
        a *= a;
        a %= m;
        b = b>>1;
    }
    return ans;
}

ll solve(){
    ll ans = -1;
    for(int i=n+1; i<p; i++){
        ans = (ans%p) * (fstPower(i,p-2,p)%p);
        ans %= p;
    }
    return (ans+p)%p;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        cin>>n>>p;
        if(p<=n){
            cout<<"0"<<endl;
        }
        else cout<<solve()<<endl;
    }
    return 0;
}
