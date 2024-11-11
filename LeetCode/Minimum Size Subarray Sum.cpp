// https://leetcode.com/problems/minimum-size-subarray-sum/
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

int minSubArrayLen(int s, vector<int>& nums) {
    int n=nums.size();
    int left=0, right=0, len = n+1, sum=0;

    while(right<n){
        while(sum<s and right<n){
            sum += nums[right++];
        }
        while(sum>=s){
            len = min(len, right-left);
            sum -= nums[left++];
        }
    }

    return (len == n+1)?0:len;
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