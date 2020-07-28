// https://leetcode.com/problems/continuous-subarray-sum/
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

bool checkSubarraySum(vector<int>& nums, int k) {
    if(nums.size()<2)
        return false;

    unordered_map<int, int>m;
    int sum=0;
    m[0]=-1;
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        if(k){
            sum %= k;
        }

        if(m.count(sum)){
            if(i-m[sum]>1)return true;
        }
        else m[sum]=i;
    }
    return false;
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