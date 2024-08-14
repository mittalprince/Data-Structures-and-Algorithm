// https://leetcode.com/problems/minimum-adjacent-swaps-to-make-a-valid-array/
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

int minimumSwaps(vector<int>& nums){
    int n = nums.size();
    int minVal=nums[0], maxVal = nums[0];
    int minIdx = 0, maxIdx= 0;

    for(int i=0; i<n; i++){
        if(minVal > nums[i]){
            minVal = nums[i];
            minIdx = i;
        }
        if(maxVal <= nums[i]){
            maxVal = nums[i];
            maxIdx = i;
        }
    }
    int ans = minIdx + (n-maxIdx-1);
    if(minIdx > maxIdx) ans--;
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