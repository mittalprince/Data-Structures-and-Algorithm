#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int dp[1005];

int solve(vector<int>&arr, int n, int i, int d){
    if(i<0 || i>=n) return 0;

    if(dp[i] != -1) return dp[i];

    int ans=1;
    for(int j=i+1; j<min(n, i+d+1) && arr[j]<arr[i]; j++){
        ans = max(ans, 1+solve(arr, n, j, d));
    }

    for(int j=i-1; j>=max(0, i-d) && arr[j]<arr[i]; j--){
        ans = max(ans, 1+solve(arr, n, j, d));
    }
    return dp[i] = ans;
}

// recursive
int maxJumps(vector<int>& arr, int d) {
    memset(dp, -1, sizeof(dp));
    int ans=0;

    int n=arr.size();
    if(n==1) return 1;

    for(int i=0; i<n; i++){
        ans = max(ans, solve(arr, n, i, d));
    }

    return ans;
}

// iterative
int maxJumps(vector<int>& A, int d) {
    vector<pair<int, int>>arr;
    for(int i=0; i<A.size(); i++){
        arr.push_back({A[i], i});
    }
    sort(arr.begin(), arr.end());

    int n=A.size();
    if(n==1) return 1;

    vector<int>dp(n+1, 0);
    // dp[i] is max jumps you can do starting from index i
    // dp[i] = 1 + max (dp[j]) where j is all indices you can reach from i.

    dp[arr[0].second]=1;

    for(int i=1; i<n; i++){
        int ht = arr[i].first;
        int idx = arr[i].second;
        int max_indices=1;

        //check in right range(idx+d)
        for(int j=idx+1; j<=min(n-1, (idx+d)); j++){
            //check all conecutive height that are smaller than ht
            if(A[j]<ht){
                max_indices = max(max_indices, 1+dp[j]);
            }
            else{
                //we break as in right range we got a height greater than ht
                // as we are given a condition that A[i]>A[k] for all indices k 
                // between i and j
                break;
            }
        }

        //check in left range(idx-d)
        for(int j=idx-1; j>=max(0, idx-d); j--){
            if(A[j]<ht){
                max_indices = max(max_indices, 1+dp[j]);
            }
            else break;
        }

        dp[idx] = max_indices;
    }

    int ans=0;
    for(int i=0; i<n; i++){
        ans = max(dp[i], ans);
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}