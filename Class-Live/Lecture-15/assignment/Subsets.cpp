#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<vector<int>> subsets(vector<int>& nums) {
    int n=nums.size();
    vector<vector<int>>ans;

    for(int i=0; i<(1<<n); i++){
        vector<int>t;
        for(int j=0; j<n; j++){
            if(i&(1<<j)){
                t.push_back(nums[j]);
            }
        }
        ans.push_back(t);
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}