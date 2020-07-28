#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    ll l,r;
	cin>>l>>r;
	int i=0;
	for(i=64; i>=0; i--){
		if((l&(1ll<<i)) ^ (r&(1ll<<i))) break;
	}
	i++;
	ll ans = (1ll<<i)-1;
	cout<<ans<<endl;
    return 0;
}