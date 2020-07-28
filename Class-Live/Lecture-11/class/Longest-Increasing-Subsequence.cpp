#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    vector<int>dp(n, 1);
    // dp[i] will denote the LIS for the given ith element
    
    for(int i=0; i<n; i++){// we traverse on every element
        for(int j=0; j<i; j++){// for every element we check if there is any smaller element exis
            // if yes we will use its LIS val and increment it by 1
            if(nums[i]>nums[j] && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
            }
        }
    }

    int ans=0;
    for(int i=0; i<n; i++){
        ans = max(dp[i], ans);
    }
    return ans;
}

/*
To print LIS
vector<int> lis;
lis.push_back(7);
len = ans (max lis len); dec it by 1; as we have considered 7

val = 7 (the val for which lis length is len)
idx = 7 ka indx -1;

while(idx){
    if(nums[idx] < val && dp[idx]==len){
        v.push_back(nums[idx]);
        val = nums[idx];
        len--;
    }
    idx--;
}
*/
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}