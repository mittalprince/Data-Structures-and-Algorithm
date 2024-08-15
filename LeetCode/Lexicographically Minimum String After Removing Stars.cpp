// https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/
#include<iostream>
#include<vector>
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

string clearStars(string s) {
    priority_queue<char, vector<char>, greater<char>>pq;
    vector<vector<int>> idx(26, vector<int>());
    char ch;
    for(int i=0; i<s.size(); i++){
        if(s[i] == "*"){
            ch = pq.top();
            s[idx[ch-'a'].back()] = '!';
            idx[ch-'a'].pop_back();
            if (idx[ch - 'a'].size() == 0){
                pq.pop();
            }
            continue;
        }
        if (idx[s[i] - 'a'].size() == 0){
            pq.push(s[i]);
        }
        idx[s[i]-'a'].push_back(i);
    }     
    string ans="";
    for(char c: s){
        if(c >= 'a') ans += c;
    }
    return ans;
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