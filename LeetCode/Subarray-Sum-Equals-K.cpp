// https://leetcode.com/problems/subarray-sum-equals-k/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int>m;
    m[0]=1;

    int sum=0, ans=0;
    for(int i: nums){
        sum += i;
        if(m.count(sum-k)){
            ans += m[sum-k];
        }

        m[sum]++;
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