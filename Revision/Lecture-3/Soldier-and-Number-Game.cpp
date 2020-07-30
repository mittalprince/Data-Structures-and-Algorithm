// https://codeforces.com/problemset/problem/546/D
#include<iostream>
#include<vector>
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
#define MAX 5000001

/*
Logic: Precalcuate the total prime factors of number 
Then use prefix sum and simply minus fcnt(a)-fcnt(b);
*/

ll factorsCnt[MAX]={0};

void sieve(){
    
    for(ll i=2; i<MAX; i++){
        if(factorsCnt[i]==0){
            factorsCnt[i]=1;
            for(ll j=2*i; j<MAX; j+=i){
                ll val = j;
                while(val%i == 0){
                    factorsCnt[j]++;
                    val /= i;
                }
            }
        }
    }

    for(ll i=2; i<MAX; i++){
        factorsCnt[i] += factorsCnt[i-1];
    }
}

void solve(){
    ll a,b;
    cin>>a>>b;
    cout<<factorsCnt[a]-factorsCnt[b]<<"\n";
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    sieve();
    while(t--){
        solve();
    }
    return 0;
}