#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n;

void solve(){
    int N=3;
    int primes[] = {2,3,5};

    ll ans=0;

    for(int i=1; i<(1<<N); i++){
        int deno = 1;
        for(int j=0; j<N; j++){
            if(i&(1<<j)){
                deno *= primes[j];
            }
        }

        int bits = __builtin_popcount(i);
        if(bits&1){
            ans += n/deno;
        }
        else ans -= n/deno;
    }

    cout<<ans<<endl;
}

int main(){
    cin>>n;
    solve();
    return 0;
}