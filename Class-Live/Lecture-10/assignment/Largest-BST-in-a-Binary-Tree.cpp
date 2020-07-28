#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class TreeNode{
    public:
    int val;
    TreeNode *left, *right;

    TreeNode() : val(0), left(NULL), right(NULL){};
    TreeNode(int v):val(v),left(NULL),right(NULL){};
};

class Pair{
    public:
    int size, mx, mi;
    bool isBst;

    Pair(){
        size=0, mx=INT_MIN, mi=INT_MAX;
        isBst=true;
    }
};

Pair largestBST(TreeNode *root){
    Pair p;
    if(root == NULL) return p;

    if(!root->left && !root->right){
        p.size=1;
        p.mx=root->val;
        p.mi=root->val;
        p.isBst=true;
        return p;
    }

    Pair left = largestBST(root->left);
    Pair right = largestBST(root->right);

    if(root->val>left.mx && root->val < right.mi && left.isBst && right.isBst){
        p.isBst=true;
        p.size = left.size+right.size+1;
        p.mx = max(root->val, max(left.mx, right.mx));
        p.mi = min(root->val, min(left.mi, right.mi));
    }
    else{
        p.isBst=false;
        p.size = max(left.size, right.size);
    }

    return p;
}
TreeNode* buildTree(int preorder[], int inorder[], int s, int e){
    static int i=0;
    if(s>e) return NULL;

    int idx=-1;
    for(int j=s; j<=e; j++){
        if(inorder[j] == preorder[i]){
            idx=j;
            break;
        }
    }
    i++;
    if(idx != -1){
        TreeNode *root = new TreeNode(inorder[idx]);
        root->left = buildTree(preorder, inorder, s, idx-1);
        root->right = buildTree(preorder, inorder, idx+1, e);

        return root;
    }
    return NULL;
}

int main(){
    int n;
    cin>>n;
    int preorder[n], inorder[n];
    ip(preorder, n);
    ip(inorder, n);
    TreeNode *root = buildTree(preorder, inorder, 0, n-1);
    Pair p = largestBST(root);
    cout<<p.size<<endl;
    return 0;
}