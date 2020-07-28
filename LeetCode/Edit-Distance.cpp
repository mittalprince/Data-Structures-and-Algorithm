// Link: https://leetcode.com/problems/edit-distance/
/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character

Logic: 
If last characters of two strings are same, nothing much to do. Ignore last characters and get count for remaining strings. So we recur for lengths m-1 and n-1.
Else (If last characters are not same), we consider all operations on ‘str1’, consider all three operations on last character of first string, recursively compute minimum cost for all three operations and take minimum of three values.
Insert: Recur for m and n-1
Remove: Recur for m-1 and n
Replace: Recur for m-1 and n-1
*/
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int minDistance(string word1, string word2) {
    int n=word1.length(), m=word2.length();

    vector<vector<int> >dp(n+1, vector<int>(m+1, INT_MAX));

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0||j==0) dp[i][j]=i+j;
            else if(word1[i-1]==word2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(dp[i][j], 1+min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])));
            // dp[i][j-1] -> insert
            // dp[i-1][j] -> del
            // dp[i-1][j-1] -> replace
        }
    }
    return dp[n][m];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string s,t;
        cin>>s>>t;
        cout<<minDistance(s, t)<<endl;
    }
    return 0;
}