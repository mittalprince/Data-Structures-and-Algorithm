// EulersPhiFunction
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

ll phi(ll n){
    ll ans=n;
    for(ll i=2; i*i<=n; i++){
        if(n%i == 0){
            while(n%i == 0) n /=i;
            ans -= ans/i;
        }
    }

    if(n>1){
        ans -= ans/n;
    }
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		cout<<phi(n)<<endl;
	}
    
    return 0;
}