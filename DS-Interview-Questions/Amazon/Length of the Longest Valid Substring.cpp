// https://leetcode.com/problems/length-of-the-longest-valid-substring/
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

class Solution{
    struct Node{
        Node *child[26];
        bool isEnd;

        Node(){
            isEnd = false;
            for(int i=0; i<26; i++) child[i] = NULL;
        }
    };
    Node *root = new Node();
    void insert(string s){
        Node *t = root;
        for(char i: s){
            if(t->child[i-'a'] == NULL) t->child[i-'a'] = new Node();
            t = t->child[i-'a'];
        }
        t->isEnd = true;
    }
    bool search(string s, int l, int r){
        Node *t = root;
        for(;l<=r; l++){
            int idx=s[l]-'a';
            if(t->child[idx]==NULL) return false;
            t=t->child[idx];
            if(t->isEnd==true) return true;
        }
        return false;
    }
public:
    int longestValidSubstring(string word, vector<string> &forbidden){
        int n = word.length();
        for(auto &words : forbidden) insert(words);
        int ans = 0;
        int j=n-1;
        for(int i=n-1; i>=0; i--){
            while(i<=j && search(word, i, j))j--;
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};


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