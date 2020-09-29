// https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/
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

int solve(vector<int>& nums1, vector<int>& nums2){
    unordered_map<long long, int>m;

    for(int i: nums1){
        long long val = (long long)i*i;
        m[val]++;
    }


    int ans=0;
    for(int i=0; i<nums2.size(); i++){
        for(int j=i+1; j<nums2.size(); j++){
            long long val = (long long)nums2[i]*nums2[j];
            ans += m[val];
        }
    }
    return ans;
}

int numTriplets(vector<int>& nums1, vector<int>& nums2) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return solve(nums1, nums2)+solve(nums2,nums1);
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