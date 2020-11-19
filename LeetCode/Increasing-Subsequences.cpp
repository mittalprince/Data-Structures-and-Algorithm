//https://leetcode.com/problems/increasing-subsequences/
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

void solve(vector<int>&nums, int i, vector<vector<int>>&ans, vector<int>&t){
    if(t.size()>1)ans.push_back(t);
    int freq[205]={0};

    for(int j=i; j<nums.size(); j++){
        if(!freq[nums[j]+100] and (t.empty() or t.back()<=nums[j])){
            freq[nums[j]+100]=1;
            t.push_back(nums[j]);
            solve(nums, j+1, ans, t);
            t.pop_back();
        }
    }
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>t;
    vector<vector<int>>ans;

    solve(nums, 0, ans, t);
    return ans; 
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