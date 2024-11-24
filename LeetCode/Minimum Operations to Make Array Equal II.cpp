// https://leetcode.com/problems/minimum-operations-to-make-array-equal-ii/
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

long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
    if(!k){
        if(nums1==nums2) return 0; 
        return -1;
    }
    long long pdiff=0, ndiff=0;
    for(int i=0; i<nums1.size();i++){
        if(nums1[i]>nums2[i]){
            pdiff += nums1[i]-nums2[i];
            if(pdiff%k)return -1;
        } else{
            ndiff += nums2[i]-nums1[i];
            if(ndiff%k)return -1;
        }
    }
    if(pdiff != ndiff) return -1;
    return pdiff/k;
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