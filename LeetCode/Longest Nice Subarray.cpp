// https://leetcode.com/problems/longest-nice-subarray/
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

int longestNiceSubarray(vector<int>& nums) {
    int AND = 0, i = 0, ans = 0, n = nums.size();
    for(int j=0; j<n; j++){
        while((AND & nums[j]) > 0){
            AND ^= nums[i++];
        }
        AND |= nums[j];
        ans = max(ans, j-i+1);
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