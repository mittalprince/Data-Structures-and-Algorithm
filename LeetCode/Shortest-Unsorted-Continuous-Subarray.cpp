//https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
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

int findUnsortedSubarray(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=nums.size();
    int end=-2, start=-1, curr_max=INT_MIN, curr_min=INT_MAX;

    for(int i=0; i<n; i++){
        curr_max = max(curr_max, nums[i]);
        if(nums[i]<curr_max){
            end=i;
        }
    }
    for(int i=n-1; i>=0; i--){
        curr_min = min(curr_min, nums[i]);
        if(nums[i]>curr_min){
            start=i;
        }
    }

    return end-start+1;
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