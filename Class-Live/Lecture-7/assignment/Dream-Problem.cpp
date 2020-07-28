#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<iterator>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"

/*
B = (A.M)/(A-M)
put x=A-M
B = ((x+M)*M)/x => M^2+Mx/x
hence M^2 must be multiple of x (as Mx/x completly)

so we need to find all value x that divide M^2----------------------

now as we know A<=B, sow when we use same above equation we find that 1<= x <= M

so know prob is to find all value of x that is samller than M and divisor of M^2
we first cal all factos of M (store in vec), then vec*vec gives all factors of M^2

*/
void solve(){
    ll n;
    cin>>n;
    vector<ll> factors;

    for(ll i=1; i*i<=(n); i++){
        if(n%i == 0){
            factors.push_back(i);
            if((n/i) != i) {
                factors.push_back(n/i);
            }
        }
    }
    ll factors_size = factors.size();
    sort(factors.begin(), factors.end());

    for(ll i=0; i<factors_size; i++){
        for(ll j=i; j<factors_size; j++){
            __uint128_t temp= (__uint128_t)factors[i]*(__uint128_t)factors[j];
            if(temp > (__uint128_t)n){
                break;
            }
            else {
                factors.push_back((ll)temp);
            }
        }
    }

    sort(factors.begin(), factors.end());
    vector<ll>::iterator it = unique(factors.begin(), factors.end());
    ll new_size = it-factors.begin();
    factors.resize(new_size);
    cout<<factors.size()<<endl;
    for(ll i: factors){
        cout<<(ll)i+n<<endl;
    }
    cout<<endl;
}

int main(){
    fstIO;
    int t;
    cin>>t;
     while(t--){
         solve();
    }
    return 0;
}