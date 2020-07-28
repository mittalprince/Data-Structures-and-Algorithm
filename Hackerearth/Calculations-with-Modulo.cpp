#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

ll binaryExponentiation(ll a, ll b, ll m){
    if(b==0)return 1;

    if(b&1){
        return (a%m)*(binaryExponentiation((a*a)%m, (b-1)/2, m))%m;
    }
    return binaryExponentiation((a*a)%m, b/2, m);
}

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b); 
}

void extendedEuclid(ll a, ll b, ll &x, ll &y, ll &d){
    if(b==0){
        x=1;
        y=0;
        d=a;
        return;
    }
    ll x1, y1;
    // ll ans = 
    extendedEuclid(b, a%b, x1, y1, d);
    x = y1;
    y = x1-(a/b)*y1;

    // return ans;
}

// when m is prime
ll modInverse(ll A,ll M){
    return binaryExponentiation(A, M - 2, M);
}

int main(){
    int a,b,c,m;
    cin>>a>>b>>c>>m;
    ll x,y,d;
    extendedEuclid(c, m, x, y,d);
    ll ans1 = binaryExponentiation(a, b, m)%m;
    ll ans2 = (x%m+m)%m;
    ll ans = ((ans1%m)*(ans2%m))%m;
    cout<<ans<<endl;
    return 0;
}