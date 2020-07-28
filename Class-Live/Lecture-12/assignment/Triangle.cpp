#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int dp[1000][1000];
int n,m;

int solve(vector<vector<int>>& t, int i, int j){
    if(i==(n-1)) return t[i][j];

    if(dp[i][j] != -1) return dp[i][j];

    int opt1 = solve(t, i+1, j);
    int opt2 = solve(t, i+1, j+1);

    return dp[i][j] = min(opt1, opt2)+t[i][j];
}

// Recusive
int minimumTotal(vector<vector<int>>& t) {
    n=t.size();
    if(n==0) return 0;

    m=t[0].size();
    if(m==0) return 0;

    if(n==1 && m==1) return t[n-1][m-1];
    memset(dp, -1, sizeof(dp));

    return solve(t, 0, 0);
}

// Iterative
int minimumTotal(vector<vector<int>>& t) {
    int ans=INT_MAX;

    for(int i=1; i<t.size(); i++){
        for(int j=0; j<t[i].size(); j++){
            int val = t[i][j];
            t[i][j] = INT_MAX;

            if(j>0) t[i][j] = min(t[i][j], t[i-1][j-1]);
            if(j<t[i].size()-1) t[i][j] = min(t[i][j], t[i-1][j]);
            t[i][j] += val;

            if(i == (t.size()-1)){
                ans = min(ans, t[i][j]);
            }
        }
    }
    return ans==INT_MAX?t[0][0]:ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}