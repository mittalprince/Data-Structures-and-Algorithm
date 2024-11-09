// https://leetcode.com/problems/maximum-xor-for-each-query/
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

vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    long long a = (1<<maximumBit)-1;
    int n = nums.size();
    vector<int>ans(n, 0), t(n, 0);
    for(int i=0; i<n; i++){
        t[i] = (i==0) ? nums[i] : t[i-1]^nums[i];
    }

    for(int i=n-1; i>=0; i--){
        ans[i] = a - t[i];
    }
    reverse(ans.begin(), ans.end());
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