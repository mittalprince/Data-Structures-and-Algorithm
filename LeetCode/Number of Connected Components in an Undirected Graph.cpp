// https://leetcode.ca/all/323.html
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

int countComponents(int n, vector<vector<int>>& edges) {
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    for (int i = 0; i < n; ++i) p[i] = i;
    function<int(int)> find = [&](int x) -> int {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    };
    for (auto& e : edges) {
        int a = e[0], b = e[1];
        p[find(a)] = find(b);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) ans += i == find(i);
    return ans;
}

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}