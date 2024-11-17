// https://leetcode.com/problems/subarrays-with-k-different-integers/
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

int atMostK(vector<int>&nums, int k){
    int n = nums.size(), i=0, ans = 0;
    unordered_map<int, int>m;
    for(int j=0; j<n; j++){
        if (!m[nums[j]]++) k--;
        while(k < 0){
            m[nums[i]]--;
            if(!m[nums[i]])k++;
            i++;
        }
        ans += j-i+1;
    }
    return ans;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
    return atMostK(nums,k) - atMostK(nums, k-1);
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