// https://leetcode.com/problems/count-number-of-nice-subarrays/
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

// int numberOfSubarrays(vector<int>& nums, int k) {
//     int n = nums.size();
//     vector<int> cnt(n + 1, 0);
//     cnt[0] = 1;
//     int ans = 0, t = 0;
//     for (int v : nums) {
//         t += v & 1;
//         if (t - k >= 0) {
//             ans += cnt[t - k];
//         }
//         cnt[t]++;
//     }
//     return ans;
// }
int numberOfSubarrays(vector<int>& nums, int k) {
    return atMost(nums, k) - atMost(nums, k - 1); 
}

int atMost(vector<int>& nums, int k) {
    int s = 0, ans = 0;
    for(int i = 0, j = 0; i < nums.size(); i++) {
        s += nums[i] % 2;
        while(s > k) s -= (nums[j++] % 2);
        ans += (i - j + 1);
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