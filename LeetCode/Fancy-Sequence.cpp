// https://leetcode.com/problems/fancy-sequence/
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

typedef long long ll;

class Fancy {
public:
    
    vector<ll>arr;
    const int MOD = 1000000007;
    ll add,mul;
    
    ll fstPow(ll a, ll b){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        ll ans=1;
        while(b){
            if(b&1){
                ans *= a;
                ans %= MOD;
            }
            a *= a;
            a %= MOD;
            b >>= 1;
        }
        return ans;
    }
    
    Fancy() {
        arr.clear();
        add=0, mul=1;
    }
    
    void append(int val) {
        val = ((val-add)%MOD +MOD)%MOD;
        val = (val * fstPow(mul, MOD-2))%MOD;
        arr.push_back(val);
    }
    
    void addAll(int inc) {
        add = (add+inc)%MOD;
    }
    
    void multAll(int m) {
        add = (add*m)%MOD;
        mul = (mul*m)%MOD;
    }
    
    int getIndex(int idx) {
        if(idx>=arr.size()){
            return -1;
        }
        return (arr[idx]*mul + add)%MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */

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