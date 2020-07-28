#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
Given a string, your task is to count how many palindromic substrings in this string.
The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/
/*
int countSubstrings(string s) {
    int n = s.size();
    vector<vector<bool>> pal(n, vector<bool>(n, false));
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int count = 0;

    for(int i=0; i<n; i++){
        pal[i][i]=true;
        dp[i][i]=1;
    }

    for(int k=2; k<=n; k++){
        for(int i=0; i<n-k+1; i++){
            int j=k+i-1;
            if(s[i] == s[j] && k==2){
                pal[i][j]=true;
                dp[i][j]=2;
            }

            if(s[i] == s[j] && pal[i+1][j-1]){
                pal[i][j]=true;
            }

            dp[i][j] = dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
            if(pal[i][j]) dp[i][j]++;
        }
    }
    return dp[0][n-1];
}
*/

int countSubstrings(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int count = 0;

    for(int i=0; i<n; i++){
        dp[i][i]=true;
        count++;
    }

    for(int k=2; k<=n; k++){
        for(int i=0; i<n-k+1; i++){
            int j=k+i-1;
            if(s[i] == s[j] && k==2){
                count++;
                dp[i][j]=true;
            }
            else if(s[i] == s[j] && dp[i+1][j-1]){
                count++;
                dp[i][j]=true;
            }
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}