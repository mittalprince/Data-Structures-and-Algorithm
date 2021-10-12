//https://leetcode.com/problems/regular-expression-matching/
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

bool isMatch(string s, string p) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=s.size();
    int m=p.size();

    bool dp[2001][2001]={0};
    // dp[i][j] -> tells s[0-i] matches with pattern[0-j] or not
    dp[0][0]=1; // empty string & empty pattern always matches

    // fill dp[0] -> means when string is empty nbut pattern not
    // can match only if * occur in patten as it replace zero or more but . replace with only char
    for(int i=1; i<=m; i++){
        if (p[i-1] == '*'){ 
            // check if pattern matches at index-1 (i-2), as curr char is *, so if dp[0][i-2] true only then dp[0][i] true
            dp[0][i] = dp[0][i-2];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if (p[j-1] == '*') {
                dp[i][j] = dp[i][j-2]; // same logic as above
                if (!dp[i][j] && (s[i-1] == p[j-2] || p[j-2] == '.')){
                    // since *, check either s[i-1] == p[j-2], as p[j-1] par * hai, so if matches till there, we replace *
                    // with 0 character, otherwise we can check if p[j-2] par. 
                    // hai ki nahi, if yes we can replace it s[i-1] and again same condition as above
                    dp[i][j] = dp[i-1][j];
                }
            } else if (p[j-1] == '.' || s[i-1] == p[j-1]) {
                // if s[i-1] == p[j-1] i.e simply check dp[i-1][j-1]
                // if p[j-1] == '.', we can place s[i-1] at p[j-1], so again above condition satisfy
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }

    return dp[n][m];
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