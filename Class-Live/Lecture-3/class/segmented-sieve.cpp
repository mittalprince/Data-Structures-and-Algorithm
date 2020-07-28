#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 1000000

vector<ll> primes;
void calculateAllPrime(){
    bool isPrime[MAX];
    memset(isPrime, true, sizeof(isPrime));
    for(ll i=3; i*i<=MAX; i+=2){
        if(isPrime[i]){
            for(ll j=i*i; j<=MAX; j+=i) isPrime[j]=false;
        }
    }
    primes.push_back(2);
    for(ll i=3; i<=MAX; i+=2){
        if(isPrime[i]) primes.push_back(i);
    }
}

// first we cal all primes upto the square root of b
// then we cancel out all no whose factors are these primes

void SegmentedSieve(ll a, ll b){
    bool p[b-a+1];
    memset(p, true, sizeof(p));

    // here we check all primes whose square is <= to b
    for(ll i=0; primes[i]*primes[i]<=b; i++){
        ll start = (a/primes[i])*primes[i];
        if(start<a)start+=primes[i];

        for(ll j=start; j<=b; j+= primes[i]){
            p[j-a]=false;
        }
        if(start == primes[i]) p[start-a]=true;
    }

    for(ll i=a; i<=b; i++){
        if(p[i-a]) cout<<i<<endl;
    }
    cout<<endl;
}
int main(){
    calculateAllPrime();
    int t;
    cin>>t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        if(a==1) a++;
        SegmentedSieve(a, b);
    }
    return 0;
}