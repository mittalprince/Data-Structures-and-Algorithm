#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int dp[505];

int solve(vector<int>&A, int n, int i, int k){
    if(i >= n) return 0;

    if(dp[i] != -1)return dp[i];

    int ans = 0;
    int mx = 0;
    for(int j = i; j<i+k && j<n; j++) {
        mx = max(mx, A[j]);
        ans = max(ans , (j-i+1)* mx + solve(A, n, j+1, k));
    }
    return dp[i] = ans;
}

// recursive
int maxSumAfterPartitioning(vector<int>& A, int k) {
    memset(dp, -1, sizeof(dp));

    int n=A.size();
    return solve(A,n,0,k);
}

//iterative
int maxSumAfterPartitioning(vector<int>& A, int k) {
    int n=A.size();
    vector<int>dp(n, 0);

    int max_val=0;
    for(int i=0; i<k; i++){
        max_val = max(max_val, A[i]);
        dp[i] = max_val*(i+1); // we cal first for less than k size window
    }

    for(int i=k; i<n; i++){
        max_val = A[i];
        // now we will consider every subarr starting A[i] in reverse direction)
        // first subarr A[i], then A[i-1],A[i] and so on 
        // last subarr will be A[i-k],A[i-k+1]....A[i]

        for(int j=1; j<=k; j++){
            max_val = max(max_val, A[i-j+1]);
            dp[i] = max(dp[i], dp[i-j]+max_val*j);
            // if we take subarr at jth idx, then what will be max partition arr sum at d[i-j] index
            // sp dp[i] = max(dp[i], dp[i-j]+max_val*j) -> we add max_val*j ad i we consider subarr at jth pint, then we follow given question rule
         }
    }

    return dp[n-1];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}