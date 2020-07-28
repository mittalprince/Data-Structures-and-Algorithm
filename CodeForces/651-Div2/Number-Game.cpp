#include<iostream>
#include<vector>
#include<cmath>
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

bool isPrime(int n){
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0)return false;
    }
    return true;
}
void solve(){
    int n;
    cin>>n;
    if(n==1){
        cout<<"FastestFinger\n";
        return;
    }
    if(n==2 or n&1){
        cout<<"Ashishgup\n";
        return;
    }
    if(((n-1)&n)==0){
        cout<<"FastestFinger\n";
        return;
    }
    int ct=0;
    while(n%2==0){
        ct++;
        n >>= 1;
    }
    if(ct==1 and isPrime(n)){
        cout<<"FastestFinger\n";
        return;
    }
    else{
        cout<<"Ashishgup\n";
        return;
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}