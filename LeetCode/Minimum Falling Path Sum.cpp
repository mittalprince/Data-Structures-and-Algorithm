// https://leetcode.com/problems/minimum-falling-path-sum/
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
    The minimum path to get to element A[i][j] is the minimum of A[i - 1][j - 1], A[i - 1][j] and A[i - 1][j + 1].
    Starting from row 1, we add the minumum path to each element. The smallest number in the last row is the miminum path sum.
    Example:
    [1, 2, 3]
    [4, 5, 6] => [5, 6, 8]
    [7, 8, 9] => [7, 8, 9] => [12, 13, 15]
*/
    
int dp[105][105];
int n,m;
int solve(vector<vector<int>>&  A, int i, int j){
    if(j<0 || j>=m) return INT_MAX;

    if(i==(n-1)){
        return A[i][j];
    }
    if(dp[i][j] != -1) return dp[i][j];

    int opt1 = solve(A, i+1, j);
    int opt2 = solve(A, i+1,j+1);
    int opt3 = solve(A, i+1, j-1);

    return dp[i][j] = min(opt1, min(opt2, opt3))+A[i][j];
}
int minFallingPathSum(vector<vector<int>>& A) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int n = A.size();
    if(n==0) return 0;

    m=A[0].size();
    if(m==0) return 0;

    memset(dp, -1, sizeof(dp));
    int ans=INT_MAX;
    for(int i=0; i<m; i++){
        // ans = min(ans, solve(A, 0, i));
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<n; j++){
            A[i][j] += min(A[i-1][j], min(A[i-1][max(0, j-1)], A[i-1][min(n-1, j+1)]));
        }
    }
    return ranges::min(A[n-1]);

}

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
*/
 
    int n;&

    ci n> > n;  
       
    vector<int> arr(n);
         
    
    return 0;
} 
                     
   
            
              
         
         
                      