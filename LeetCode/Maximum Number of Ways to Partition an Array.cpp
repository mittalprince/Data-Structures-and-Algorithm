// https://leetcode.com/problems/maximum-number-of-ways-to-partition-an-array/
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

int waysToPartition(vector<int>& nums, int k) {
    // https://leetcode.com/problems/maximum-number-of-ways-to-partition-an-array/discuss/1498999/C%2B%2B-O(n)
    int n = nums.size();
    vector<long long> prefix(n, 0), suffix(n, 0);
    prefix[0] = nums[0], suffix[n-1] = nums[n-1];

    for(int i=1; i<n; i++){
        prefix[i] = prefix[i-1] + nums[i];
        suffix[n-1-i] = suffix[n-i] + nums[n-1-i];
    }
    long long ans = 0;
    unordered_map<long long, long long>left, right;
    for(int i=0; i<n-1; i++){
        right[prefix[i]-suffix[i+1]]++;
    }
    if(right.count(0)) ans = right[0];

    for(int i=0; i<n; i++){
        long long curr = 0, diff = k-nums[i];
        if(left.count(diff)) curr+=left[diff];
        if(right.count(-diff)) curr+=right[-diff];

        ans = max(ans, curr);
        if(i<n-1){
            long long dd = prefix[i]-suffix[i+1]; 
            left[dd]++; right[dd]--;
            if(right[dd] == 0) right.erase(dd);
        }
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