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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        
        if(root->val > key){
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if(root->val == key){
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            if(root->left && !root->right){
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            if(!root->left && root->right){
                TreeNode *temp=root->right;
                delete root;
                return temp;
            }
            
            TreeNode *replace = root->right;
            while(replace->left) replace = replace->left;
            
            root->val = replace->val;
            root->right = deleteNode(root->right, replace->val);
            return root;
        }
        else{
            root->right = deleteNode(root->right, key);
            return root;
        }
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}