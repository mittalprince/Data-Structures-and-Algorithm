#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int jump(vector<int>& nums) {
    int n=nums.size();
    int max_reach=0, max_end=0, ans=0;


    for(int i=0;i<n-1; i++){
        max_reach = max(max_reach, i+nums[i]);
        if(max_end == i){
            ans++;
            max_end = max_reach;
        }
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}