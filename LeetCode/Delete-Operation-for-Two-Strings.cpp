//https://leetcode.com/problems/delete-operation-for-two-strings/
#include<iostream>
#include<vector>
#include<cstring> 
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, 
where in each step you can delete one character in either string.

we can use LCS and then ans will be (n+m-2*lcs[n][m])

other than
ifi==0||j==0) i.e one string is empty than to make string equal will be (i+j)
if(s[i-1]==t[i-1]) then we don't need any del operation so ans will be d[i][j] = dp[i-1][j-1]
else dp[i][j]=min(dp[i-1][j], dp[i][j-1])+1;

dp[i][j] refers to the number of deletions required to equalize the two strings
if we consider the strings' length upto (i-1)(j−1) index for s1s1 and s2s2 respectively.

*/
int minDistance(string word1, string word2) {
    int n=word1.length(), m=word2.length();

    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0||j==0) dp[i][j]=i+j;
            else if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j]=min(dp[i-1][j], dp[i][j-1])+1;
        }
    }
    return dp[n][m];
}

int minDistance(string text1, string text2) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=text1.size(),m=text2.size();
    int i,j;
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(text1[i-1]==text2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    return n+m-2*dp[n][m];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}