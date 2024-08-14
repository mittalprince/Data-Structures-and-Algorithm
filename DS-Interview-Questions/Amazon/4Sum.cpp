// https://leetcode.com/problems/4sum/
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

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>res;

    if(nums.empty())return res;
    sort(nums.begin(), nums.end());

    for(int i=0; i<nums.size(); i++){
        if(i>0 and nums[i] == nums[i-1])continue;

        for(int j=i+1; j<nums.size(); j++){
            if(j>i+1 and nums[j] == nums[j-1])continue;

            int s=j+1;
            int e=nums.size()-1;

            while(s<e){
                long long sum = (long long)nums[s]+nums[e]+nums[i]+nums[j];
                if(sum == target){
                    res.push_back({nums[i],nums[j],nums[s],nums[e]});
                    while(s<e and nums[s] == nums[s+1])s++;
                    while(e>s and nums[e]==nums[e-1])e--;
                    s++;
                    e--;
                }
                else if(sum>target) e--;
                else s++;
            }
        }
    }
    return res;
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