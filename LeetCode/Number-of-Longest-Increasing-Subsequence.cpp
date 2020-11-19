//https://leetcode.com/problems/number-of-longest-increasing-subsequence/
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

int findNumberOfLIS(vector<int>& nums) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n=nums.size();
    vector<pair<int,int> >dp(n, {1,1}); // {length, numbdr of LIS ends with nums[i]}

    int max_len=0, ans=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(nums[i]>nums[j]){
                if(dp[i].first == dp[j].first+1){
                    dp[i].second += dp[j].second;
                }
                else if(dp[i].first<dp[j].first+1){
                    dp[i] = {dp[j].first+1, dp[j].second};
                }
            }        
        }
        if(max_len == dp[i].first)ans += dp[i].second;
        if(max_len<dp[i].first){
            max_len = dp[i].first;
            ans = dp[i].second;
        }
    }
    return ans;
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