// https://leetcode.com/problems/count-number-of-bad-pairs/discuss/2388183/n*(n-1)2-Valid-oror-(C%2B%2BJava)
#include<iostream>
#include<vector>
#include<map>
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


long long countBadPairs(vector<int>& nums) {
    map<int, long long>m;
    long long n=nums.size();
    long long ans=n*(n-1)/2;

    for(int i=0;i<n; i++){
        m[nums[i]-i]++;
    }
    for(auto it: m){
        ans -= it.second*(it.second-1)/2;
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