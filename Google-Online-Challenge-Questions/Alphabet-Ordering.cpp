// https://leetcode.com/discuss/interview-question/794983/Google-or-OA-2020-or-Alphabet-Ordering-and-Maximum-Subarray
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

/*

Input:
6
abcdcba
gfcbdhdd
ffdhhbbbdeeggbb
cadhfbbacf
hheaadbdgdggd
hcbehahccaag

Output:
2
3
4
4
5
5
*/

void solve(){
    string s;
    cin>>s;

    int n=s.length();
    int flag=0; // starting of substring
    // flag = 1 increasing
    // flag = -1 decreasing
    int ans=0; // count total broken point, so final ans will be ans+1 substrings
    for(int i=1; i<n; i++){
        if(flag==0){
            if(s[i]==s[i-1])continue;
            if(s[i]>s[i-1])flag=1;
            else flag=-1;
        }
        else if(flag==1){
            if(s[i]>=s[i-1])continue;
            else{
                ans++;
                flag=0;
            }
        }
        else{
            if(s[i]<=s[i-1])continue;
            else{
                flag=0;
                ans++;
            }
        }
    }

    cout<<ans+1<<endl;
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

/*
dp[i][0] means min splits that you need to create when current character is part of increasing seq and dp[i][1] is for decreasing.

Want more, then here is the code:

if(s[i] > s[i-1) {
    dp[i][0] = dp[i-1][0];
} else {
    dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + 1;
}

if(s[i] < s[i-1) {
    dp[i][1] = dp[i-1][1];
} else {
    dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + 1;
}
*/