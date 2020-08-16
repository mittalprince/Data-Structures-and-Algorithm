// https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/
#include<iostream>
#include<vector>
#include<map>
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

map<int, int>dp;

int minDays(int n) {
    if(n<=1)return n;

    if(dp.count(n))return dp[n];
    int ans=INT_MAX;

    ans = min(ans, minDays(n/2)+(n&1)+1);
    ans = min(ans, minDays(n/3)+n%3+1);

    return dp[n]=ans;
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