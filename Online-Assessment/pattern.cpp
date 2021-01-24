/*
Given a number N. check wether the binary representation of N contain 10 and 01 only.

Hint: 
Check if a number has bits in alternate pattern 
(https://www.geeksforgeeks.org/check-number-bits-alternate-pattern-set-2-o1-approach/)
*/
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

void solve(){
    ll n;
    cin>>n;

    n = n^(n>>1);
    if(n&(n+1)){
        cout<<"NO\n";
    }
    else cout<<"YES\n";
}

void solve(){
    ll n;
    cin>>n;
    bool flag=true;
    int prev_bit=n&1;
    n >>= 1;
    while(n){
        int curr_bit=n&1;
        if(curr_bit==prev_bit){
            flag=false;
            break;
        }
        prev_bit=curr_bit;
        n >>= 1;
    }
    if(flag){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}