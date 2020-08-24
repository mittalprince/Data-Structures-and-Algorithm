// https://leetcode.com/problems/ugly-number-iii/
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

ll gcd(ll a, ll b){
    if(b==0)return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a/gcd(a,b)*b;
}

ll find(ll mid, ll a, ll b, ll c){
    return (mid/a+mid/b+mid/c) - (mid/lcm(a,b)+mid/lcm(b,c)+mid/lcm(a,c)) + mid/lcm(a, lcm(b,c));
}

int nthUglyNumber(int n, int a, int b, int c) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll l=1, r=(int)2e9;
    ll ans;
    while(l<=r){
        ll mid = (l+r)/2;
        if(find(mid, a, b, c) < n){
            l = mid+1;
        }
        else{
            r=mid-1;
            ans = mid;
        }
    }

    return ans;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}