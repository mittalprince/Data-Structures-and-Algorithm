// https://leetcode.com/problems/add-and-search-word-data-structure-design/
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

class WordDictionary {
public:
   class trienode{
        public:
        bool isleaf;
        trienode* letters[26];
    
        trienode(){
            isleaf=false;
            fill_n(letters,26,nullptr);
        }
        
    };
    
 
    trienode* root;
    
    WordDictionary() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        root=new trienode();
    }
    
    
    void addWord(string word) {
        trienode*n=root;
        for(int i=0; i<word.size(); i++){
            int index=word[i]-'a';
 
            if(!n->letters[index]){
                n->letters[index]=new trienode();
            }
            n=n->letters[index];
        }
        n->isleaf=true;
    }
    
    bool search(string word) {
        return search(word, 0, root);
    }
    
    bool search(string &word, int index, trienode* root){
        if(index>=word.size()) return root->isleaf;
        if(word[index]=='.'){
           for(int i=0; i<26; i++){
                if(root->letters[i] && search(word, index+1, root->letters[i])){
                    return true;
                }
           }
            return false;    
        } else {
            int j=word[index]-'a';
            if(!root->letters[j]) return false;
            return search(word, index+1, root->letters[j]);
        }
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