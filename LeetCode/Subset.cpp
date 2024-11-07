// https://leetcode.com/problems/subsets/
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

void solve(vector<int>& nums, int i, vector<int>&t, vector<vector<int>>&ans){
    if(nums.size() == i){
        ans.push_back(t);
        return;
    }
    solve(nums, i+1, t, ans);
    t.push_back(nums[i]);
    solve(nums, i+1, t, ans);
    t.pop_back();
}
vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>>ans;
    vector<int>t;
    solve(nums, 0, t, ans);
    return ans;
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