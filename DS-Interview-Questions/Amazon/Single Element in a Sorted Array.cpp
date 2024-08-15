// https://leetcode.com/problems/single-element-in-a-sorted-array/
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

int singleNonDuplicate(vector<int>& nums) {
    int e=nums.size()-1, s=0;

    while(s<e){
        int mid = (s+e)/2;
        if((mid%2 == 0 && nums[mid]==nums[mid+1]) || (mid%2 == 1 && nums[mid] == nums[mid-1])){
            s=mid+1;
        }
        else e=mid;
    }
    return nums[s];
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