#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class TreeNode{
    public:
    int val;
    TreeNode *left, *right;

    TreeNode():val(0),left(NULL),right(NULL){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool helper(TreeNode *root){
        if(root==NULL) return false;
        
        bool left=helper(root->left);
        bool right=helper(root->right);
        
        if(!left) root->left=NULL;
        if(!right) root->right=NULL;
        
        return (root->val == 1)||left||right;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        bool ans = helper(root);
        
        if(!ans) return NULL;
        return root;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}