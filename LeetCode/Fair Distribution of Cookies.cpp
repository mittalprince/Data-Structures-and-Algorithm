// https://leetcode.com/problems/fair-distribution-of-cookies/
// https://leetcode.com/problems/fair-distribution-of-cookies/discuss/2140918/Easy-C%2B%2B-or-Backtracking
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

int ans = INT_MAX;
void solve(int start, vector<int>& nums, vector<int>& v, int k){
    if(start==nums.size()){
        int maxm = INT_MIN;
        for(int i=0;i<k;i++){
            maxm = max(maxm,v[i]);
        }
        ans = min(ans,maxm);
        return;
    }
    for(int i=0;i<k;i++){
        v[i] += nums[start];
        solve(start+1,nums,v,k);
        v[i] -= nums[start];
        if (v[i] == 0){ // optimmization (point to be noted)
            break;
        }
    }
}

int distributeCookies(vector<int>& nums, int k) { // nums is the cookies vector
    int n = nums.size();
    vector<int> v(k,0); // v is to store each sum of the k subsets
    solve(0,nums,v,k);
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