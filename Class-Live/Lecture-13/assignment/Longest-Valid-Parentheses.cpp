#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int longestValidParentheses(string s) {
    int n=s.length();
    
    vector<int>dp(n, 0);
    int ans=0;
    
    for(int i=1; i<n; i++){
        if(s[i] == '('){
            dp[i]=0;
        }
        else{
            if(i-1-dp[i-1]>=0 && s[i-1-dp[i-1]]=='('){
                dp[i]=dp[i-1]+2;
                if(i-2-dp[i-1]>=0){
                    dp[i]+=dp[i-2-dp[i-1]];
                }
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    return 0;
}