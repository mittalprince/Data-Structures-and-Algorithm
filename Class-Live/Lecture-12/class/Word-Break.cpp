#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

map<string, bool> m;
int *dp;

int solve(string s, int pos){
    if(pos == s.length()){
        return 1;
    }

    if(dp[pos] != -1) return dp[pos];
    
    for(int end=pos+1; end<=s.length(); end++){
        string x = s.substr(pos, end-pos);
        if(m.count(x) && solve(s, end)){
            return dp[pos]=1;
        }
    }
    return dp[pos]=0;
}
bool wordBreak(string s, vector<string>& wordDict) {
    for(string i: wordDict){
        m[i]=true;
    }
    dp = new int[s.length()+1];
    for(int i=0; i<=s.length(); i++){
        dp[i] = -1; 
    }
    return solve(s, 0);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}