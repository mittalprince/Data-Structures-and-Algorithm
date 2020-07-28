// https://www.interviewbit.com/problems/maximum-sum-square-submatrix/
// https://www.geeksforgeeks.org/print-maximum-sum-square-sub-matrix-of-given-size/
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

int solve(vector<vector<int> > &A, int k) {
    int n=A.size();
    
    vector<vector<int> >preSum(n, vector<int>(n, 0));
    
    for(int j=0; j<n; j++){
        int sum=0;
        
        for(int i=0; i<k; i++){
            sum += A[i][j];
        }
        preSum[0][j]=sum;
        
        for(int i=1; i<n-k+1; i++){
            sum += A[i+k-1][j]-A[i-1][j];
            preSum[i][j]=sum;
        }
    }
    
    int ans=INT_MIN;
    
    for(int i=0; i<n-k+1; i++){
        int sum=0;
        for(int j=0; j<k; j++){
            sum += preSum[i][j];
        }
        ans = max(ans, sum);
        
        for(int j=1; j<n-k+1; j++){
            sum += preSum[i][j+k-1] - preSum[i][j-1];
            ans = max(ans, sum);
        }
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