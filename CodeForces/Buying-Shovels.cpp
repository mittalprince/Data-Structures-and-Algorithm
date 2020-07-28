#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve(){
    ll n,k;
    cin>>n>>k;

    if(n<=k){
        cout<<"1\n";
        return;
    }

    ll ans=-1;
    for(ll i=1; i*i<=n; i++){
        if(n%i == 0){
            if(i<=k){
                ans = max(ans, i);
            }
            if(n/i != i){
                if((n/i)<=k){
                    ans = max(ans, n/i);
                }
            }
        }
    }

    cout<<(n/ans)<<endl;
}

int main(){
    int t;
    cin>>t;
     while(t--){
         solve();
    }
    return 0;
}