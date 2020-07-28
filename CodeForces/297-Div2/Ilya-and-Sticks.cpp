// https://codeforces.com/contest/525/problem/C
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
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
#define MAX 1000005

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    ll freq[MAX]={0};
    for(int i=0; i<n; i++){
        ll x;
        cin>>x;
        freq[x]++;
    }

    vector<ll>arr;
    for(int i=MAX-1; i>=1; i--){
        while(freq[i]>=2){
            arr.push_back(i);
            freq[i] -=2;
        }
        if(freq[i] and freq[i-1]){
            arr.push_back(i-1);
            freq[i]--;
            freq[i-1]--;
        }
    }

    ll ans=0;
    arr.push_back(0);
    for(ll i=0; i<arr.size()-1; i+=2){
        ans += arr[i]*arr[i+1];
    }
    cout<<ans<<endl;
    return 0;
}