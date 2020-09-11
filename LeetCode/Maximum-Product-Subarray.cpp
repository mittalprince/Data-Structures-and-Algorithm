// https://leetcode.com/problems/maximum-product-subarray/
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

int maxProduct(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=nums.size();
    if(n==0)return 0;

    int ans = nums[0];
    int prev_max = nums[0];
    int prev_min=nums[0];

    for(int i=1; i<n; i++){
        int curr_max = max(prev_max*nums[i], max(prev_min*nums[i], nums[i]));
        int curr_min = min(prev_max*nums[i], min(prev_min*nums[i], nums[i]));

        ans = max(ans, curr_max);
        prev_max = curr_max;
        prev_min = curr_min;
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