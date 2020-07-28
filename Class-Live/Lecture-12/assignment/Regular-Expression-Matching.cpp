#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

bool isMatch(string s, string p) {
    int m=p.size();
    int n=s.size();

    bool dp[2001][2001]={0};
    dp[0][0]=1;
    // dp sotre at dp[i][j] if text[:i] and pattern[:j] can be a match

    for(int i=1; i<=m; i++){
        if(p[i-1] == '*') dp[0][i] = dp[0][i-2]; // we check at (i-2) at string is empty and pattern is not
        // so we check with zero occurence of char  when * come which is at i-2
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(p[j-1] == '*'){
                dp[i][j] = dp[i][j-2]; // match zero occurenece

                // otherwise we check the same pattern with string len-1, it this cell is true
                // then we check either we can get this s[i-1] using p[i-1] that is *
                // so if s[i-1] == p[j-2] (j-2 will be just prev of *) or p[j-2] == '.' (means we can replace it with any char)
                // we update dp[i][j]
                if(!dp[i][j] && ((s[i-1] == p[j-2]) || p[j-2] == '.')){
                    dp[i][j] = dp[i][j] || dp[i-1][j];
                }   
            }
            else if(s[i-1] == p[j-1] || p[j-1] == '.'){
                dp[i][j] = (true&&dp[i-1][j-1]);    
            }
        }
    }
    return dp[n][m];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}