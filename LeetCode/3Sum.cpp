// https://leetcode.com/problems/3sum/
#include<iostream>
#include<vector>
#include<algorithm>
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

vector<vector<int>> threeSum(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n=nums.size();
    vector<vector<int>>res;
    int target=0;
    
    if(n==0){
        return res;
    }
    sort(nums.begin(), nums.end());
    
    for(int i=0; i<n; i++){
        if(i>0 and nums[i]==nums[i-1])continue;
        
        int s=i+1;
        int e=n-1;
        
        while(s<e){
            int val = nums[i]+nums[s]+nums[e];
            if(val == target){
                res.push_back({nums[i], nums[s], nums[e]});
                while(s<e and nums[s]==nums[s+1])s++;
                while(s<e and nums[e]==nums[e-1])e--;
                s++;
                e--;
            }
            else if(val>target)e--;
            else s++;
        }
    }
    
    return res;
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