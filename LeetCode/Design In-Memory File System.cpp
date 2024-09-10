// https://leetcode.com/problems/design-in-memory-file-system/
#include<iostream>
#include<vector>
#include<unordered_map>
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

class FileSystem {
    struct FileNode{
        unordered_map<string, FileNode*> next;
        bool isFile;
        string content;
        FileNode(): isFile(false), content(""){}
    };

    FileNode *root;
    FileNode* goToPathFolder(string path){
        FileNode *curr = root;
        stringstream s(path);
        string folder;
        while(getline(s, folder, '/')){
            if(folder.size()){
                if(!curr->next.count(folder)) curr->next[folder] = new FileNode();
                curr = curr->next[folder];
            }
        }
        return curr;
    }
public:
    FileSystem() {
        root = new FileNode();
    }
    
    vector<string> ls(string path) {
        FileNode *curr = goToPathFolder(path);
        vector<string>ans;

        if (cur->isFile) {
            return {path.substr(path.find_last_of('/') + 1)};
        }

        for(auto it: curr->next){
            ans.push_back(it.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    void mkdir(string path) {
        FileNode *curr = goToPathFolder(path);
    }
    
    void addContentToFile(string filePath, string content) {
        FileNode *curr = goToPathFolder(filePath);
        curr->content += content;
        curr->isFile = true;
    }
    
    string readContentFromFile(string filePath) {
        FileNode *curr = goToPathFolder(filePath);
        return curr->content;
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