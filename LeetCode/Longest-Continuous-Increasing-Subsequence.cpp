//https://leetcode.com/problems/longest-continuous-increasing-subsequence/
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

int findLengthOfLCIS(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(nums.size()==0) return 0;
    int ans=0, last=0;

    for(int i=1; i<nums.size(); i++){
        if(nums[i-1]<nums[i])
            ans++;
        else
            ans=0;
        if(last < ans){
            last = ans;
        }
    }
    return last+1;
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