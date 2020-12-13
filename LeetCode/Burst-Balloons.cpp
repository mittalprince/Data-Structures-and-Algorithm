//https://leetcode.com/problems/burst-balloons/
#include<iostream>
#include<vector>
#include<climits>
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

int maxCoins(vector<int>& nums) {
    int dp[505][505]={0};
    
    int n=nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    
    for(int d=1; d<=n; d++){
        int i=1, j=d;
        while(j<=n){
            int ans=INT_MIN;
            for(int k=i; k<=j; k++){
                ans = max(ans, dp[i][k-1]+dp[k+1][j] + nums[i-1]*nums[k]*nums[j+1]);
            }
            dp[i][j]=ans;
            i++;
            j++;
        }
    }
    
    return dp[1][n];
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