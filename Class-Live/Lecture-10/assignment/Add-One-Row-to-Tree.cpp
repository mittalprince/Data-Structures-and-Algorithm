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
    void helper(TreeNode *root, int val, int d){
        if(root==NULL) return;
        
        if(d == 1){
            TreeNode *left=root->left, *right=root->right;
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            root->left->left=left;
            root->right->right=right;
            return;
        }
        helper(root->left, val, d-1);
        helper(root->right, val, d-1);
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1){
            TreeNode *t=new TreeNode(v);
            t->left = root;
            return t;
        }
        helper(root, v, d-1);
        return root;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}