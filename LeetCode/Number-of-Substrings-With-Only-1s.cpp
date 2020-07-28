// https://leetcode.com/problems/number-of-substrings-with-only-1s/
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

const int mod = 1000000007;

int numSub(string s) {
    unsigned long long ans=0;
    unsigned long long ct=0;

    for(char i: s){
        if(i=='0'){
            unsigned long long t = (ct*(ct+1))/2;
            t %= mod;
            ans += t;
            ans %= mod;
            ct=0;
        }
        else ct++;
    }

    if(ct){
        unsigned long long t = (ct*(ct+1))/2;
        t %= mod;
        ans += t;
        ans %= mod;
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