// https://leetcode.com/problems/subsets-ii/
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

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int start = 0;
    vector<vector<int>>ans = {{}}; // initiall adding empty set
    for(int i=0; i<n; i++){
        /*
        idea is simple if item is not duplicate, just push into all prev comb
        that's why in that case we reset start = 0;
        otherwise if duplicate, will push item to new comb that got created in prev loop
        */
        if(i==0 || nums[i] != nums[i-1]) start = 0;
        for(int end = ans.size(); start<end; start++){
            vector<int> clone = ans[start];
            clone.push_back(nums[i]);
            ans.push_back(clone);
        }
    }
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