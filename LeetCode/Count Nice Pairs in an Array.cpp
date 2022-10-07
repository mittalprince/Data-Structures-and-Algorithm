// https://leetcode.com/problems/count-nice-pairs-in-an-array/
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

// https://leetcode.com/problems/count-nice-pairs-in-an-array/discuss/1140487/Count-Frequency-of-difference-of-number-and-its-reverse-or-Easy-Hashmap-Explained
const int mod=1000000007;
int rev(int n){
    int ans=0;
    while(n) {
        ans = ans*10 + n%10;
        n/=10;
    }
    return ans;
}
int countNicePairs(vector<int>& nums) {
    map<int, long>m;
    for(int i=0; i<nums.size(); i++){
        m[nums[i]-rev(nums[i])]++;
    }
    long ans=0;
    for(auto it: m){
        ans = (ans + (it.second*(it.second-1))/2)%mod;
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