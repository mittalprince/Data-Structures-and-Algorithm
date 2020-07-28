// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

bool search(vector<int>& nums, int target) {
    int s=0, e=nums.size()-1;

    while(s<=e){
        int mid = (s+e)/2;
        if(nums[mid] == target or nums[s]==target or nums[e]==target){
            return true;
        }
        if(nums[s]<nums[mid]){
            if(target>nums[s] and target<nums[mid]){
                e=mid-1;
            }
            else s=mid+1;
        }
        else if(nums[mid]<nums[e]){
            if(nums[mid]<target and nums[e] > target){
                s=mid+1;
            }
            else e=mid-1;
        }
        else e--;
    }
    return false;
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