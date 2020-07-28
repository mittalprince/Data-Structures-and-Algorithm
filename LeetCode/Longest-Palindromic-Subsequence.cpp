#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

string str;
vector<vector<int> > memo;

int solve(int i, int j){
    if(i>j) return 0;
    if(i==j) return 1;

    if(memo[i][j] != -1) return memo[i][j];

    int ans=0;
    if(str[i] == str[j]){
        ans = 2+solve(i+1, j-1);
    }
    else ans = max(solve(i+1, j),solve(i, j-1));

    return memo[i][j]=ans;
}

int longestPalindromeSubseq(string s) {
    memo.resize(s.size(), vector<int>(s.size(), -1));
    str = s;
    return solve(0, s.size()-1);
}

// iterative
int longestPalindromeSubseq(string s) {
    int n=s.length();

    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    for(int i=0; i<n; i++){
        dp[i][i]=1;
    }

    for(int k=2; k<=n; k++){
        for(int i=0; i<n-k+1; i++){
            int j=i+k-1;

            if(s[i] == s[j] && k==2){
                dp[i][j]=2;
            }
            else if(s[i]==s[j]){
                dp[i][j] = dp[i+1][j-1]+2;
            }
            else{
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }

    return dp[0][n-1];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}