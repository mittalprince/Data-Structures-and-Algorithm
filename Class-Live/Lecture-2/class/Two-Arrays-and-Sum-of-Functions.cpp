#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define mod 998244353
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];

bool comp(ll a, ll b){
    return a>b;
}

int main(){
    int n;
    cin>>n;
    ll a[n], b[n];
    ip(a,n);
    ip(b,n);
    for(int i=0; i<n; i++){
        a[i] = a[i]*(i+1)*(n-i);
    }
    ll sum=0;
    sort(a, a+n);
    sort(b, b+n, comp);
    for(int i=0; i<n; i++){
        sum += (b[i]%mod)*(a[i]%mod);
        sum %= mod;
    }
    cout<<sum<<endl;
    return 0;
}