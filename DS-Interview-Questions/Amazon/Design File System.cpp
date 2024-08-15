// https://leetcode.com/problems/design-file-system/
#include<iostream>
#include<vector>
#include<sstream>
#include<unordered_map>
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

class FileSystem {
private:
    class TrieNode {
        public:
            unordered_map<string, TrieNode *> child;
            int content;

            TrieNode(){
                content = -1;
            }
    };
    TrieNode *root = NULL;

    vector<string> split(string& s){
        stringstream ss(s);
        string path;

        vector<string>res;
        int i=0;
        while(getline(ss, path, '/')){
            if(i++) res.push_back(path);
        }
        return res;
    }

    bool insert(vector<string>& arr, int value){
        int n = arr.size();
        TrieNode *curr = root;
        for(int i=0; i<n; i++){
            if(curr->child.count(arr[i])){
                if( i == n-1)return false; // the path already exist
            } else {
                if(i != n-1) return false; // parent path does't exist, return false
                curr->child[arr[i]] = new TrieNode();
            }
            curr = curr->child[arr[i]];
        }
        curr->content = value;
        return true;
    }

    int search(vector<string>& arr){
        int n = arr.size();
        TrieNode *curr = root;
        for(int i=0; i<n; i++){
            if(!curr->child.count(arr[i])) return -1;
            curr = curr->child[arr[i]];
        }
        return curr->content;
    }
public:
    FileSystem() {
        root = new TrieNode();
    }
    
    bool createPath(string path, int value) {
        vector<string> p = split(path);
        return insert(p, value);
    }
    
    int get(string path) {
        vector<string> p = split(path);
        return search(p);
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