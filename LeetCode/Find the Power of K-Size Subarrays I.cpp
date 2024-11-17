// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/
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

vector<int> resultsArray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int>ans(n-k+1, -1);
    int score = 0;
    for(int i=0; i<n; i++){
        if(i && nums[i-1]+1 == nums[i]) score++;
        else score = 0;
        if(score >= k-1) ans[i-k+1] = nums[i];
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