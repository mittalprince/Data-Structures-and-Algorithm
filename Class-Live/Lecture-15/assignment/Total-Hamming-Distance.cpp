#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int totalHammingDistance(vector<int>& nums) {
    int ans=0;

    for(int i=31; i>=0; i--){
        int one=0, zero=0;
        for(int j=0; j<nums.size(); j++){
            if((nums[j]>>i)&1)one++;
            else zero++;
        }
        ans += (one*zero);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}