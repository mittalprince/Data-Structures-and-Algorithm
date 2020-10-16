// https://leetcode.com/problems/make-sum-divisible-by-p/
#include<iostream>
#include<vector>
#include<unordered_map>
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

int minSubarray(vector<int>& nums, int p) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(p==1)return 0;
    int sum=0;
    for(int i: nums){
        sum += i;
        sum %= p;
    }

    if(sum==0)return 0;
    const int n = nums.size();
    unordered_map<int, int> m;
    int ans = n;

    m[0]=-1;
    int curr=0;
    for(int i=0; i<n; i++){
        curr += nums[i];
        curr %= p;

        int t = (curr-sum+p)%p;
        if(m.count(t)){
            ans = min(ans, i-m[t]);
        }
        m[curr]=i;
    }

    return ans==n?-1:ans;
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