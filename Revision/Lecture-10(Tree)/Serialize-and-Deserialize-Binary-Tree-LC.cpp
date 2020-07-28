// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
#include<iostream>
#include<vector>
#include<ostream>
#include<sstream>
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

class TreeNode{
public:
    int val;
    TreeNode *left, *right;
    TreeNode():val(0),left(NULL),right(NULL){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    void encode(TreeNode* node, ostringstream& ss){
        ss<<to_string(node->val);
        
        if(node->left){
            ss<<"l";
            encode(node->left, ss);
            ss<<"u";
        }
        
        if(node->right){
            ss<<"r";
            encode(node->right, ss);
            ss<<"u";
        }
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        ostringstream ss;
        
        encode(root, ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())return NULL;
        
        TreeNode *root = new TreeNode(0);
        stack<TreeNode*>p;
        p.push(root);
        
        int start=0;
        int i=1;
        
        while(i<data.size()){
            if(data[i] >= '0' and data[i] <= '9' or data[i] == '-'){
                i++;
                continue;
            }    
            
            TreeNode *node = p.top();
            if(i-start>0) node->val = stoi(data.substr(start, i-start));
            
            if(data[i] == 'l'){
                node->left = new TreeNode(0);
                p.push(node->left);
            }
            else if(data[i] == 'r'){
                node->right = new TreeNode(0);
                p.push(node->right);
            }
            else if(data[i] == 'u'){
                p.pop();
            }
            i++;
            start=i;
        }
        
        if(i - start > 0 && !p.empty()){
            auto node = p.top();
            node->val = stoi(data.substr(start, i - start));
        }
        return root;
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