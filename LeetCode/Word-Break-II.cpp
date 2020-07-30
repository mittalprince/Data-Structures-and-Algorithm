// https://leetcode.com/problems/word-break-ii/
#include<iostream>
#include<vector>
#include<unordered_map>
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

vector<string> solve(string s, int idx, unordered_set<string>&wordDict, unordered_map<int, vector<string> >&dp){

    int len = s.length();
    if(idx == len)return {""};

    if(dp.count(idx) == 0){
        string prefix = "";
        vector<string> possible;
        for(int i=idx; i<len; i++){
            prefix += s[i];
            if(wordDict.count(prefix)){
                vector<string> next_possible = solve(s, i+1, wordDict, dp);

                if(next_possible.size()){
                    for(string nxt: next_possible){
                        if(nxt != ""){
                            possible.push_back(prefix+" "+nxt);
                        }
                        else{
                            possible.push_back(prefix);
                        }
                    }
                }
            }
        }
        dp[idx] = possible;
    }
    return dp[idx];
}

vector<string> wordBreak(string s, vector<string>& wordList) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_set<string>wordDict;
    for(string i: wordList){
        wordDict.insert(i);
    }

    unordered_map<int, vector<string> >dp;

    return solve(s, 0, wordDict, dp);
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