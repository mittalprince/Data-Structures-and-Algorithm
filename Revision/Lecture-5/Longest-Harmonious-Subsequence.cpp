// https://leetcode.com/problems/longest-harmonious-subsequence/
#include<iostream>
#include<vector>
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

int findLHS(vector<int>& nums) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    unordered_map<int, int> mp;
    for(auto x:nums)
        mp[x]++;
    int size = mp.size(), len=0;
    for(auto x:mp)
        if(mp.find(x.first+1) != mp.end())
            len = max(len, x.second+mp[x.first+1]);
    return len;
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