//https://leetcode.com/problems/longest-common-prefix/
#include<iostream>
#include<vector>
#include<map>
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

string longestCommonPrefix(vector<string>& strs){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string ans = "";
    int idx = 0;

    for(const char& c: strs[0]){
        for(int v = 1; v<strs.size(); v++){
            if (strs[v].size() <= idx || strs[v][idx] != c)return ans;
        }
        ans += c;
        idx++;
    }
    return ans;
}

class node{
    public:
    int child;
    map<char, node*>m;
    bool isEnd;
    node(){
        child = 0;
        isEnd = false;
    }
};

class trie{
    node *root;
    public:
    trie(){
        root = new node();
    }
    
    void insert(string s){
        node *temp = root;
        for(int i=0; i<s.length(); i++){
            if(temp->m.find(s[i]) == temp->m.end()){
                temp->m[s[i]] = new node();
                temp->child++;
            }
            temp = temp->m[s[i]];
        }
        temp->isEnd = true;
    }
    
    string search(string s){
        string ans="";
        node *temp = root;
        for(int i=0; i<s.length(); i++){
            if(temp->child > 1 || temp->isEnd){
                return ans;
            }
            ans += s[i];
            temp = temp->m[s[i]];
        }
        return ans;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        string ans="";
        int n=strs.size();
        if(n == 0){
            return ans; 
        }
        if(n==1){
            return strs[0];
        }
        
        trie root;
        for(int i=0; i<n; i++){
            root.insert(strs[i]);
        }
        ans = root.search(strs[0]);
        return ans;
    }
};

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