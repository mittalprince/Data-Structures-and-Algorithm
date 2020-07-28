#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    string s,t;
    cin>>s>>t;
    int n=s.length(), m=t.length();

    ll dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0||j==0) dp[i][j]=0;
            else if(s[i-1]==t[j-1]) dp[i][j]= dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    string ans="";
    int len=dp[n][m]-1;
    int i=n, j=m;

    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            ans += s[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]) i--;
        else j--;
    }

    int str=0;
    while(str<len){
        swap(ans[str], ans[len]);
        str++;
        len--;
    }
    cout<<ans<<endl;
    return 0;
}