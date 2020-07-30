// https://codeforces.com/contest/546/problem/B
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
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


int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    
    map<ll,ll>m;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        m[x]++;
    }
    ll ans=0;
    for(int i=1; i<1000000; i++){
        ans += max(0ll,m[i]-1);
        m[i+1]+= max(0ll,m[i]-1);
    }
    cout<<ans<<endl;

    return 0;
}

/*
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
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


int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    ll ans=0;
    map<ll, bool> m;

    for(int i=0; i<n; i++){
        int val = arr[i];
        while(m.count(val)!=0){
            val++;
        }
        m[val]=true;
        ans += val-arr[i];
    }
    
    cout<<ans<<endl;

    return 0;
}*/