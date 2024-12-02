// https://leetcode.com/problems/identify-the-largest-outlier-in-an-array/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
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

int getLargestOutlier(vector<int>& nums) {
    unordered_map<int, int>m;
    long long sum = 0;
    for(int i: nums){
        m[i]++;
        sum += i;
    }
    int ans = INT_MIN;
    for(int i: nums){
        m[i]--;
        int t = sum - i;
        if(!(t&1) && m[t/2])ans = max(ans, i);
        m[i]++;
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