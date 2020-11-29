//https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
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

int minimumMountainRemovals(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=nums.size();
    vector<int>left(n,1), right(n,1);

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(nums[i]>nums[j] && left[i]<left[j]+1){
                left[i]=left[j]+1;
            }
        }
    }

    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>i; j--){
            if(nums[i]>nums[j] && right[i]<right[j]+1){
                right[i]=right[j]+1;
            }
        }
    }

    int ans=0;
    for(int i=1; i<n-1; i++){
        ans = max(ans, left[i]+right[i]-1);
    }

    return n-ans;
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