// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
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

vector<int> twoSum(vector<int>& nums, int target) {
    int n=nums.size();
    int s=0, e=n-1;

    while(s<e){
        if(nums[s]+nums[e] == target){
            return {s+1, e+1};
        }
        if(nums[s]+nums[e]<target)s++;
        else e--;
    }
    return {};
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