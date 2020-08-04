// https://codeforces.com/contest/451/problem/C
// Refer: https://codeforces.com/contest/451/submission/7233730
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

void solve(){
    ll n,k,d1,d2;
    cin>>n>>k>>d1>>d2;

    if(n%3){
        cout<<"no\n";
        return;
    }

    for(int sign1=-1; sign1<=1; sign1++){
        for(int sign2=-1; sign2<=1; sign2++){
            if(sign1==0 or sign2==0)continue;

            ll a1 = d1*sign1;
            ll a2 = d2*sign2;

            ll x2 = (k-a1+a2)/3;
            if((k-a1+a2)%3)continue;

            if(x2>=0 and x2<=k){
                ll x1 = a1+x2;
                ll x3 = x2-a2;
                if(x1>=0 and x1<=k and x3>=0 and x3<=k){
                    if(x1<=n/3 and x2<=n/3 and x3<=n/3){
                        cout<<"yes\n";
                        return;
                    }
                } 
            }
        }
    }
    cout<<"no\n";
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