// https://codeforces.com/contest/808/problem/C
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
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

    int n,w;
    cin>>n>>w;
    vector<pair<int, int> >arr(n);
    vector<int>ans(n);
    for(int i=0; i<n; i++){
        cin>>arr[i].first;
        arr[i].second=i;
        ans[i] = ceil(arr[i].first*1.0/2);
        w -= ans[i];
    }
    if(w<0){
        cout<<"-1\n";
        return 0;
    }
    sort(arr.rbegin(), arr.rend());
    for(int i=0; i<n; i++){
        ll t=w;
        t -= min(arr[i].first-ans[arr[i].second], w);
        ans[arr[i].second] += min(arr[i].first - ans[arr[i].second], w);
        w = t;
        if(w<0) break;
    }

    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}