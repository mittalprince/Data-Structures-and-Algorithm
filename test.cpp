#include<iostream>
#include<vector>
#include<cstring>
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
#define MAX 1000050

ll smalles_prime_factor[MAX+1];
ll total_factors_cnt[MAX+1];
ll prefix[MAX+1];

void find_smallest_prime_factors(){
	memset(smalles_prime_factor, 0, sizeof(smalles_prime_factor));

	for(ll i=0; i<=MAX; i++){
		smalles_prime_factor[i]=i;
	}
	for(ll i=4; i<=MAX; i+=2){
		smalles_prime_factor[i]=2;
	}

	for(ll i=3; i*i<=MAX; i+=2){
		if(smalles_prime_factor[i]==i){
			for(ll j=i*i; j<=MAX; j+=i){
				if(smalles_prime_factor[j]==j){
					smalles_prime_factor[j]=i;
				}
			}
		}
	}
}

void preCompute(){
	total_factors_cnt[1] = prefix[1] = 1;
 
    for (ll i=2; i<=MAX; i++){
 
        ll mspf = smalles_prime_factor[i];
        ll prim = mspf;
        ll temp = i;
        ll cnt = 0;
 
        while (temp % mspf == 0) {
            temp /= mspf;
            cnt += 1;
            prim = prim * mspf;
        }
 
        total_factors_cnt[i] = (cnt + 1)* total_factors_cnt[temp];
 
        prefix[i] = prefix[i - 1]+total_factors_cnt[i];
    }
}

void solve(){
	ll k;
	cin>>k;

	ll start = 1;
    ll end = MAX - 1;
 
    while(start<end){

        ll mid = (start + end) / 2;
        if (prefix[mid] == k){
			cout<<mid<<endl;
			return;
		}
        else if (prefix[mid] < k)
            start = mid + 1;
        else end = mid;
    }
 
    cout<<start<<endl;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	find_smallest_prime_factors();
	preCompute();
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}