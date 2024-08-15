// https://leetcode.com/problems/design-search-autocomplete-system/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
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

class AutocompleteSystem {
    struct TrieNode{
        unordered_map<char, TrieNode*> next;
        bool isEnd;
        int count;
        string word;

        TrieNode(): isEnd(false), count(0), word(""){}
    };

    struct comp{
        bool operator()(const pair<int, string>&a, pair<int, string>&b){
            if(a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        }
    };

    priority_queue<pair<int, string>, vector<pair<int, string>>, comp>pq;
    TrieNode *root;
    string prefix = "";

    void insert(string& sentence, int times=1){
        TrieNode *node = root;
        for(char c: sentence){
            if(!node->next.count(c)){
                node->next[c] = new TrieNode();
            }
            node = node->next[c];
        }
        node->count += times;
        node->isEnd = true;
        node->word = sentence;
    }

    void dfs(TrieNode *curr){
        if(curr->isEnd){
            pq.push({ curr->count, curr->word});
            if(pq.size()>3) pq.pop();
        }
        for(auto node: curr->next){
            dfs(node.second);
        }
    }
    vector<string> search(string prefix){
        TrieNode *curr = root;
        for(char ch: prefix){
            if(!curr->next.count(ch)) return {};
            curr = curr->next[ch];
        }
        dfs(curr);

        vector<string>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        for(int i=0; i<times.size(); i++){
            insert(sentences[i], times[i]);
        }

    }
    
    vector<string> input(char c) {
        if (c == '#'){
            insert(prefix, 1);
            prefix = "";
            return {};
        }
        prefix += c;
        return search(prefix);
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