//https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/
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

vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=nums.size();
    vector<int>prefix(n);
    for(int i=0; i<n; i++){
        prefix[i] = nums[i] + (i?prefix[i-1]:0);
    }

    vector<int>ans(n);

    for(int i=0; i<n; i++){
        ans[i] = (nums[i]*i - (i?prefix[i-1]:0)) + (prefix[n-1]-prefix[i] - nums[i]*(n-i-1));
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