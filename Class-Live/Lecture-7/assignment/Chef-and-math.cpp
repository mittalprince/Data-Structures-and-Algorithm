#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
#define MAX 43
#define endl "\n"

ll arr[50]={0};

ll totalWays(ll x, ll k, ll i){
    if(x==0&&k==0){
        return 1;
    }
    if(x==0||k==0||i<0) return 0;

    ll ct=totalWays(x, k, i-1);
    //optimization
    // here we check the max and min value that can we obtained from given ith fib
    // so min will be arr[i] && max will be k*arr[i]
    // so if x lie within this range we call take this arr[i], dec k and sum, but not i as we can use same many times
    if(x-arr[i]>=0 && x <= k*arr[i]){
        ct += totalWays(x-arr[i],k-1, i);
    }
    return ct;
}
int main(){
    fstIO;
    int n;
    arr[0]=1;
    arr[1]=2;
    for(int i=2; i<MAX; i++){
        arr[i] = arr[i-1]+arr[i-2];
    }

    int q;
    cin>>q;
    while(q--){
        ll x,k;
        cin>>x>>k;
        ll ct = totalWays(x, k, MAX-1);
        cout<<(ct%MOD)<<endl;
    }
    return 0;
}