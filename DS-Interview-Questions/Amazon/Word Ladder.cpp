// https://leetcode.com/problems/word-ladder/
#include<iostream>
#include<vector>
#include<set>
#include<queue>
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

int solve(string beginWord, string target, set<string>&s){
    if(s.find(target) == s.end())return 0;
    int level=0, wordLen = target.size();
    queue<string>q;
    q.push(beginWord);

    while(!q.empty()){
        level++;
        int sz = q.size();
        for(int i=0; i<sz; i++){
            string top = q.front();
            q.pop();
            
            for(int pos=0; pos<wordLen; pos++){
                char actual_val = top[pos];
                for(char c='a'; c<='z'; c++){
                    top[pos] = c;
                    if(top == target)return level+1;
                    if(s.find(top) == s.end())continue; 
                    q.push(top);
                    s.erase(top);
                }
                top[pos] = actual_val;
            }
        }
    }
    return 0;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList){
    set<string>s(wordList.begin(), wordList.end());
    return solve(beginWord, endWord, s);
}

int main(){

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