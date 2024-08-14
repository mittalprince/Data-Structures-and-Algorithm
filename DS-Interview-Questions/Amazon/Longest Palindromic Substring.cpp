// https://leetcode.com/problems/longest-palindromic-substring/
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

// TC - O(N^2), SC - O(N^2)
string longestPalindrome(string s) {
    int n = s.length();
    if(n==1)return s;
    vector<vector<bool>>dp(n, vector<bool>(n,0));
    int start=0, maxLen = 1;
    for(int i=0; i<n; i++){
        dp[i][i]=true;
    }
    for(int i=0; i<n-1; i++){
        if(s[i]==s[i+1]){
            dp[i][i+1]=true;
            start = i;
            maxLen = 2;
        }
    }
    for(int k=3; k<=n; k++){
        for(int i=0; i<n-k+1; i++){
            int j = i+k-1;
            if(dp[i+1][j-1] && s[i]==s[j]){
                dp[i][j] = true;
                if(k>maxLen){
                    start = i;
                    maxLen = k;
                }
            }
        }
    }
    return s.substr(start, maxLen);
}

string longestPalindrome(string s) {
    int n = s.length();
    if(n==1) return s;
    int start=0, end=1;

    int l,r;
    // at each index, we consider it as center of palindrom
    // use two pointer approach and expand the string in both direction
    // at each index 2 condition odd length string/even length string
    for(int i=0; i<n; i++){
        // Find longest palindromic substring of even size
        l = i-1;
        r = i;
        while(l>=0 && r<n && s[l] == s[r]){
            if(r-l+1 > end){
                start=l;
                end = r-l+1;
            }
            l--;
            r++;
        }
        // Find longest palindromic substring of odd size
        l = i-1;
        r = i+1;
        while(l>=0 && r<n && s[l] == s[r]){
            if(r-l+1 > end){
                start=l;
                end = r-l+1;
            }
            l--;
            r++;
        }
    }
    return s.substr(start, end);
}

int main()
{

    /*
        #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        #endif
    */

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}