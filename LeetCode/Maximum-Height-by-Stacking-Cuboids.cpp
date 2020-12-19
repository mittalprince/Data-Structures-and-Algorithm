//https://leetcode.com/problems/maximum-height-by-stacking-cuboids/
#include<iostream>
#include<vector>
#include<algorithm>
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

int maxHeight(vector<vector<int>>& A) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    for(vector<int>&i: A){
        sort(begin(i), end(i));
    }

    A.push_back({0,0,0});
    sort(begin(A), end(A));

    int n=A.size();
    int ans=0;
    vector<int>dp(n);

    for(int j=1; j<n; j++){
        for(int i=0; i<j; i++){
            if (A[i][0] <= A[j][0] && A[i][1] <= A[j][1] && A[i][2] <= A[j][2]) {
                dp[j] = max(dp[j], dp[i] + A[j][2]);
                ans = max(ans, dp[j]);
            }
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