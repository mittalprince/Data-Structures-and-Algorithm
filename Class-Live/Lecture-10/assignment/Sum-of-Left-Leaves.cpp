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
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root, bool left=false) {
        if(root==NULL) return 0;
        if(!root->left && !root->right && left) return root->val;
        return sumOfLeftLeaves(root->left, true)+sumOfLeftLeaves(root->right, false);
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}