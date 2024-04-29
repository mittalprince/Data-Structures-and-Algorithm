//https://leetcode.com/problems/find-missing-and-repeated-values/
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

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size();
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mp[grid[i][j]]++;
        }
    }

    int miss, repeat;
    for (int i = 1; i <= n * n; i++) {
        if (mp[i] == 2)
            repeat = i;
        if (mp[i] == 0)
            miss = i;
    }

    return {repeat, miss};
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