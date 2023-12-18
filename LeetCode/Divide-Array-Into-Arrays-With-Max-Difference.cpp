//https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/
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

vector<vector<int>> divideArray(vector<int>& nums, int k) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int i = 2; i < nums.size(); i += 3){
        if(nums[i] - nums[i - 2] > k) return {};
        ans.push_back({nums[i-2], nums[i-1], nums[i]});
    }
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