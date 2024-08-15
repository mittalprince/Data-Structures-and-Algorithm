// https://leetcode.com/problems/permutations/
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

vector<vector<int> >ans;
void solve(vector<int>&nums, int i){
    if(i==nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int j=i; j<nums.size(); j++){
        swap(nums[i], nums[j]);
        solve(nums, i+1);
        swap(nums[j], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    solve(nums, 0);
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