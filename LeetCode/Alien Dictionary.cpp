// https://leetcode.ca/2016-08-25-269-Alien-Dictionary/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
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

string alienOrder(vector<string>& A){
    unordered_map<int, unordered_set<int>>g;
    int inDegree[26] = {};
    for(auto& s: A){
        for(char& i: s) g[i-'a'] = {};
    }
    for(int i=1; i<A.size(); i++){
        int j=0;
        for(; j<min(A[i-1].size(), A[i].size()); j++){
            if(A[i-1][j] == A[i][j]) continue;
            g[A[i-1][j]-'a'].insert(A[i][j]-'a');
            break;
        }
        if(j==A[i].size() && j<A[i-1].size()) return "";
    }
    for(auto& node: g){
        for(int& child: g[node]){
            inDegree[child]++;
        }
    }
    queue<int>q;
    for(int i=0; i<26; i++){
        if(g.count(i) && !inDegree[i])q.push(i);
    }
    string ans="";
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans += u + 'a';
        for(int child: g[u]){
            if(--inDegree[child]==0)q.push(child);
        }
    }
    return ans.size() == g.size() ? ans : "";
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