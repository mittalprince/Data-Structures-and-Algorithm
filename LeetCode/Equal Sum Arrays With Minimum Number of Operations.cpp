// https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/
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

int minOperations(vector<int>& nums1, vector<int>& nums2) {
    int s1 =0, s2 = 0;
    for(int &x: nums1) s1 += x;
    for(int &x: nums2) s2 += x;
    if(s1 > s2) swap(nums1, nums2), swap(s1, s2);

    // from here sum(nums1) <= sum(nums2) ie, s1 <= s2
    // now our task is to make both s1 and s2 equal by some good operations.
    // we have two ways to do that 
    //      1. either increase some elements to '6' in nums1.
    //      2. decrease some elements to '1' in nums2.

    int ans = 0, diff = s2 - s1; // so,  we need to recover this 'diff'.
    if(diff == 0) return 0;

    vector<int>arr;
    for(int &x: nums1) arr.push_back(6 - x);
    // 6 - x signifies how much increment it does if we change a element 'x' to '6' in nums1 in one operation. ( 1st way )
    // this operation increases s1 by '6 - x', (diff = s2 - s1) (as s1 increases then diff decreases).

    for(int &x: nums2) arr.push_back(x - 1);
    // similarly, x - 1 signifies how much decrement it does if we change a element 'x' to '1' in nums2 in one operation. (2nd way)
    // this operation decreases s2 by 'x - 1', (diff = s2 - s1) (as s2 decreases then diff decreases).

    sort(arr.rbegin(), arr.rend());
    // sorting in desending order to pick the most valuable operation that decreases the 'diff'. (Yes, Greedy)

    for(int &x: arr){
        ans++; 
        diff -= x;
        if(diff <= 0) return ans; // at some operation may diff == 0 
        // if diff < 0 then we can adjust last operation to our needs.
    }
    return -1;
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