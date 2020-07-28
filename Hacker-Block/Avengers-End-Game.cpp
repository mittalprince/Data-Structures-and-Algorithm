#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

ll n;

ll solve(){
    int primes[] = {2,3,5,7,11,13,17,19};
    int N=8;
    ll ans=0;
    for(int i=1; i<(1<<N); i++){
        ll deno=1;
        for(int j=0; j<N; j++){
            if(i&(1<<j)){
                deno *= primes[j];
            }
        }
        ll bits = __builtin_popcount(i);
        if(bits&1){
            ans += n/deno;
        }
        else ans -= n/deno;
    }
    return ans;
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<solve()<<endl;
    }    
    return 0;
}