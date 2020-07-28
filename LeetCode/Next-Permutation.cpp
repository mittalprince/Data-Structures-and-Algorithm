#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void nextPermutation(vector<int>& nums) {

    int n = nums.size();
    int ind = -1;
    // find the index where we should do the re-arrangement
    for(int i = n-2; i >= 0; --i) {
        if(nums[i] < nums[i+1]) {
            ind = i;
            break;
        }
    }
    
    // if no index is found, it means we have the largest possible permuation
    
    // find the second index to swap the number at first index with
    if(ind != -1) {
        int ind2 = ind + 1;
        for(int i = ind + 1; i < n; ++i) {
            if(nums[i] > nums[ind]) {
                ind2 = i;
            }
        }
        swap(nums[ind], nums[ind2]);
    }
    
    sort(nums.begin() + ind + 1, nums.end()); 
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}