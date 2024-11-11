// https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/
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

int minimumSubarrayLength(vector<int>& nums, int k) {
    vector<int>count(32, 0);
    int start = 0, end = 0, minLength = INT_MAX, n = nums.size();

    while(end < n){
        updateBits(count, nums[end], 1);
        while(start<=end && getVal(count) >= k){
            minLength = min(minLength, end-start+1);
            updateBits(count, nums[start], -1);
            start++;
        }
        end++;
    }
    return minLength == INT_MAX ? -1 : minLength;
}
void updateBits(vector<int>& count, int num, int val){
    for(int i=0; i<32; i++){
        if(num&(1<<i)){
            count[i] += val;
        }
    }
}
int getVal(const vector<int>& count) {
    int ans = 0;
    for(int i=0; i<32; i++){
        if(count[i]) ans |= (1<<i);
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