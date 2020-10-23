// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n=nums.size();
    vector<int>ans;

    for(int i=0; i<n; i++){
        int idx = abs(nums[i])-1;
        if(nums[idx]>0){
            nums[idx] *= -1;
        }
    }

    for(int i=0; i<n; i++){
        if(nums[i]>0) ans.push_back(i+1);
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