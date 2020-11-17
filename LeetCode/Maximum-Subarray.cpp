//https://leetcode.com/problems/maximum-subarray/
#include<iostream>
#include<vector>
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

int maxSubArray(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=nums.size();
    int curr_sum=0, max_sum=INT_MIN;

    for(int i=0; i<n; i++){
        curr_sum += nums[i];
        if(max_sum<curr_sum){
            max_sum = curr_sum;
        }
        if(curr_sum<0){
            curr_sum=0;
        }
    }

    return max_sum;
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