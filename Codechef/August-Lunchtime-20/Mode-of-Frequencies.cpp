// https://www.codechef.com/problems/MODEFREQ
#include<iostream>
#include<vector>
#include<unordered_map>
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

void solve(){
    int n;
    cin>>n;
    unordered_map<int, int>m1, m2;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        m1[x]++;
    }
    for(auto it: m1){
        m2[it.second]++;
    }
    
    vector<pair<int, int> >arr;
    for(auto it:m2){
        arr.push_back({it.second, it.first});
    }
    sort(arr.begin(), arr.end(), [&](auto a, auto b)->bool{
        if(a.first==b.first)return a.second<b.second;
        return a.first>b.first;
    });

    cout<<arr[0].second<<endl;
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