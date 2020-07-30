// https://www.spoj.com/problems/PRIME1/cstart=10
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
#define MAX 100005

vector<ll>primes;

void sieve(){
    bool isPrime[MAX];
    memset(isPrime, 1, sizeof(isPrime));

    for(ll i=3; i*i<MAX; i+=2){
        if(isPrime[i]){
            for(ll j=i*i; j<MAX; j+=i){
                isPrime[j]=false;
            }
        }
    }
    primes.push_back(2);
    for(ll i=3; i<MAX; i+=2){
        if(isPrime[i])primes.push_back(i);
    }
}

void SegmentedSieve(ll a, ll b){
    bool p[b-a+1];
    memset(p, 1, sizeof(p));

    for(ll i=0; primes[i]*primes[i]<=b; i++){
        ll start = (a/primes[i])*primes[i];
        if(start<a) start+=primes[i];

        for(ll j=start; j<=b; j+=primes[i]){
            p[j-a]=false;
        }

        if(start==primes[i]) p[start-a]=true;
    }

    for(ll j=a; j<=b; j++){
        if(p[j-a])cout<<j<<"\n";
    }
    cout<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    sieve();
    while(t--){
        ll a,b;
        cin>>a>>b;
        if(a==1)a++;
        SegmentedSieve(a,b);    
    }
    return 0;
}