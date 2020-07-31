// https://codeforces.com/contest/1388/problem/A
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

    int a=6,b=10,c=14;
    if(n<=(a+b+c)){
        cout<<"NO\n";
        return;
    }
    if((n-(a+b+c))==a or (n-(a+b+c))==b or (n-(a+b+c))==c)c++;

    cout<<"YES\n";
    cout<<a<<" "<<b<<" "<<c<<" "<<(n-(a+b+c))<<endl;
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