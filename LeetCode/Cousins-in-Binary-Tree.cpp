#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
Return true if and only if the nodes corresponding to the values x and y are cousins.
*/

class TreeNode{
    public:
    int val;
    TreeNode *left, *right;

    TreeNode():val(0),left(NULL),right(NULL){};
};

void helper(TreeNode *root, TreeNode *parent, int curr_depth, int x, int y, int &dx, int &dy, TreeNode* &xp, TreeNode* &yp){
    if(root==NULL) return;
    if(root->val == x){
        dx=curr_depth;
        xp = parent;
        return;
    }
    if(root->val == y){
        dy=curr_depth;
        yp = parent;
        return;
    }

    helper(root->left, root, curr_depth+1, x, y, dx, dy, xp, yp);
    helper(root->right, root, curr_depth+1, x, y, dx, dy, xp, yp);
}

bool isCousins(TreeNode* root, int x, int y) {
    if(root==NULL) return false;
    TreeNode *px=NULL, *py=NULL;
    int dx=-1, dy=-1;

    helper(root,NULL,0,x,y,dx,dy,px,py);
    if(px==NULL||py==NULL||dx==-1||dy==-1) return false;

    if(dx == dy && px != py) return true;
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}