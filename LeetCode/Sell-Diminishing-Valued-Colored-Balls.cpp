//https://leetcode.com/problems/sell-diminishing-valued-colored-balls/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
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

map<int, int, greater<>> m;
bool isPossible(int M, int T) {
    for (auto &[n , cnt] : m) {
        if (n <= M) break;
        T -= (long)cnt * (n - M);
        if (T <= 0) return true;
    }
    return T <= 0;
}

int maxProfit(vector<int>& arr, int orders) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long s=0, e=*max_element(begin(arr), end(arr));
    for(int i: arr){
        m[i]++;
    }

    while(s<=e){
        int mid = (s+e)/2;
        if(isPossible(mid, orders)){
            s=mid+1;
        }
        else e=mid-1;
    }
    long ans = 0, mod = 1e9+7;

    for(auto &[n, cnt]: m){
        if(n<=s)break;
        orders -= cnt*(n-s);
        ans = (ans + (n + s + 1) * (n - s) / 2 % mod * cnt % mod) % mod;
    }

    if(orders){
        ans = (ans + s * orders % mod) % mod;
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