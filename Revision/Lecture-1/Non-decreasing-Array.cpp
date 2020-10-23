//https://leetcode.com/problems/non-decreasing-array/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

bool checkPossibility(vector<int>& nums) {
    int n=nums.size();

    int opt1=0, opt2=0;
    int prev = nums[0];

    for(int i=1; i<n; i++){
        prev = max(prev, nums[i]);
        if(nums[i]<prev) opt1++;
    }
    if(opt1<=1) return true;

    prev = nums[n-1];
    for(int i=n-2; i>=0; i--){
        prev = min(prev, nums[i]);
        if(nums[i]>prev)opt2++;
        if(opt2>1) return false;
    }
    return true;
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