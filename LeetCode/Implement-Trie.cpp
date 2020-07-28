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

class Trie {
public:
    class TrieNode{
        public:
        char val;
        int ct, endsHere;
        TrieNode *child[26];

        TrieNode(){

        }
        TrieNode(char a){
            val = a;
            ct=endsHere=0;
            for(int i=0; i<26; i++){
                child[i]=NULL;
            }
        }
    };

    TrieNode *root;

    /** Initialize your data structure here. */
    Trie() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        root = new TrieNode('\0');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *temp = root;
        for(char i: word){
            if(temp->child[i-'a'] == NULL){
                temp->child[i-'a'] = new TrieNode(i);
            }
            temp->child[i-'a']->ct++;
            temp = temp->child[i-'a'];
        }
        temp->endsHere++;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *temp = root;
        for(char i: word){
            if(temp->child[i-'a']==NULL)return false;
            temp = temp->child[i-'a'];
        }
        return (temp->endsHere>0);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *temp = root;
        for(char i: prefix){
            if(temp->child[i-'a']==NULL)return false;
            temp = temp->child[i-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

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