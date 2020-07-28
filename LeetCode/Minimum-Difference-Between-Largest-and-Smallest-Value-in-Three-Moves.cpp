// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/
#include<iostream>
#include<vector>
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

int minDifference(vector<int>& nums) {    
    sort(nums.begin(), nums.end());
    int n=nums.size();

    if(n<=3)return 0;
    int ans = nums[n-1]-nums[0];
    for(int i=0, j=n-4; j<n; i++, j++){
        ans = min(ans, nums[j]-nums[i]);
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