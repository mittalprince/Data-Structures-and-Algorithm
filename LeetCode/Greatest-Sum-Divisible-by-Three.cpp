// https://leetcode.com/problems/greatest-sum-divisible-by-three/
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

/*
Logic: 2-D Dp
State 1. total consider element
      2. modulo with 3

dp[i][j] -> we have total i elements and j is modulo with 3 and it store the max sum we can obtain.

SO we first make dp[i][j] = dp[i-1][j] means intially the max sum will be without consider this element
then if we  want to add this element we check what will be the max sum prev we can obtain then add nums[i-1] (as indexing is from 1) to
check the final val and then mod with it.

Then we check if we add this wether it gives max sum than its prev if yes update
*/

int maxSumDivThree(vector<int>& nums) {
    int n=nums.size();
    int dp[n+1][3];
    for(int i=0; i<3; i++){
        dp[0][i]=0;
    }

    for(int i=1;  i<=n; i++){
        for(int j=0; j<3; j++){
            dp[i][j] = dp[i-1][j];
        }
        for(int j=0; j<3; j++){
            int val1 = nums[i-1]+dp[i-1][j];
            int val2 = val1%3;
            dp[i][val2] = max(dp[i][val2], val1);
        }
    }
    return dp[n][0];
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