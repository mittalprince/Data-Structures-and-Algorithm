#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class NumArray {
    vector<int> sums;
public:
    NumArray(vector<int>& nums) {
        sums = vector<int>(nums.size()+1);
        for (int i = 1; i <= nums.size(); i++)
            sums[i] = sums[i-1] + nums[i-1];
    }
    
    int sumRange(int i, int j) {
        return sums[j+1] - sums[i];
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}