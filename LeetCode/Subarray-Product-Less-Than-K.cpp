// https://leetcode.com/problems/subarray-product-less-than-k/
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

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(k<=1)return 0;

    int ans=0;
    int prod=1;
    int left=0, i=0;
    int n=nums.size();

    while(i<n and left<=i){
        prod *= nums[i];
        while(prod>=k){
            prod /= nums[left];
            left++;
        }

        if(prod<k){
            ans += (i-left+1);
        }
        i++;
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