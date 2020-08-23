// https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/nobita-in-trouble-2-5ce82e3d/
#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

ll fstPow(ll a, ll b){
    ll ans=1;
    while(b){
        if(b&1){
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}

void solve(){
    ll n;
    cin>>n;
    vector<ll>ans;
    int ct=0;
    while(n){
        if(n&1){
            ans.push_back(fstPow(3, ct));
        }
        n >>= 1;
        ct++;
    }
    cout<<ans.size()<<endl;
    for(ll i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
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
    while(t--){
        solve();
    }
    return 0;
}