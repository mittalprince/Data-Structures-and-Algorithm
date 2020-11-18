//https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
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

int minOperations(vector<int>& nums, int x) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int totalsum=0;
    for(int i:nums){
        totalsum += i;
    }

    int sum = totalsum-x;
    if(sum<0)return -1;
    if(sum==0)return nums.size();

    int n=nums.size();
    int len=-1;
    int left=0, right=0, curr=0;

    while(right<n){
        while(curr<sum and right<n){
            curr += nums[right++];
        }
        while(curr>=sum){
            if(curr==sum){
                len = max(len, right-left);
            }
            curr -= nums[left++];
        }
    }

    if(len==-1)return len;
    return n-len;
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