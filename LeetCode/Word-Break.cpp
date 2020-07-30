// https://leetcode.com/problems/word-break/
#include<iostream>
#include<vector>
#include<unordered_set>
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

bool solve(string s, int pos, unordered_set<string>&m, int dp[]){
    if(pos==s.length())return 1;

    if(dp[pos] != -1)return dp[pos];

    for(int end=pos+1; end<=s.length(); end++){
        string x = s.substr(pos, end-pos);
        if(m.count(x) and solve(s, end, m, dp)){
            return dp[pos]=1;
        }
    }
    return dp[pos]=0;
}

bool wordBreak(string s, vector<string>& wordDict) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_set<string>m;

    for(string i: wordDict){
        m.insert(i);
    }

    int dp[s.length()+1];
    for(int i=0; i<=s.length(); i++){
        dp[i] = -1; 
    }

    return solve(s, 0, m, dp);
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