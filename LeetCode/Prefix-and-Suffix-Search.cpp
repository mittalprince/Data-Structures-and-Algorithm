// https://leetcode.com/problems/prefix-and-suffix-search/
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

/*
Hint -----------
For a word like "test", consider "#test", "t#test", "st#test", "est#test", "test#test". 
Then if we have a query like prefix = "te", suffix = "t", we can find it by searching for something we've inserted starting with 
"t#te".
*/
class WordFilter{
private:
    class TrieNode
    {
    public:
        int idx;
        bool isEnd;
        TrieNode *child[27];

        TrieNode()
        {
            idx = -1;
            isEnd = false;
            for (int i = 0; i < 27; i++)
            {
                child[i] = NULL;
            }
        }
        ~TrieNode()
        {
            for (int i = 0; i < 27; i++)
            {
                if (child[i])
                    delete child[i];
            }
        }
    };

public:
    TrieNode *root;

    void insert(string word, int pos){
        TrieNode *temp = root;
        for (char i : word){
            if (temp->child[i - 'a'] == NULL)
                temp->child[i - 'a'] = new TrieNode();
            temp->idx = pos;
            temp = temp->child[i - 'a'];
        }
        temp->idx = pos;
        temp->isEnd = true;
    }

    int search(string word){
        TrieNode *temp = root;
        for (char i : word)
        {
            if (temp->child[i - 'a'] == NULL)
                return -1;
            temp = temp->child[i - 'a'];
        }
        return temp->idx;
    }

    WordFilter(vector<string> &words){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        root = new TrieNode();

        for (int i = 0; i < words.size(); i++){
            string t = words[i];
            string s = "{" + t;
            insert(s, i);

            for (int j = t.size() - 1; j >= 0; j--)
            {
                s = t[j] + s;
                insert(s, i);
            }
        }
    }

    int f(string prefix, string suffix){
        suffix += "{" + prefix;
        return search(suffix);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
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