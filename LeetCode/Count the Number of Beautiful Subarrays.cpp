// https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/
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

long long beautifulSubarrays(vector<int>& nums) {
    unordered_map<int, int>m{{0,1}};
    long long ans = 0, pre = 0;
    for(int i: nums){
        pre ^= i;
        ans += m[pre]++;
    }
    return ans;
}

long long beautifulSubarrays(vector<int>& nums) {
    unordered_map<int, long long> mp;
    long long ans = 0;
    int val = 0;
    mp[val] = 1;
    for(auto n: nums){
        val = val^n;
        mp[val]++;
    }
    for(auto m: mp){
        ans += ((m.second -1)*m.second)/2;
    }
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