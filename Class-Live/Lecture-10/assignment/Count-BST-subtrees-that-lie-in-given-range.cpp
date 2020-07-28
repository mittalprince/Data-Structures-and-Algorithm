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

    TreeNode():val(0),left(NULL),right(NULL){};
    TreeNode(int v):val(v),left(NULL),right(NULL){};
};

bool countSubtree(TreeNode *root, int l, int h, int &ct){
    if(root==NULL) return true;

    bool left = countSubtree(root->left, l, h, ct);
    bool right = countSubtree(root->right, l, h, ct);

    if(root->val>=l && root->val<=h && left && right){
        ct++;
        return true;
    }
    return false;
}
TreeNode* buildTree(int arr[], int s, int e){
    if(s>e) return NULL;
    int mid = (s+e)/2;

    TreeNode *root = new TreeNode(arr[mid]);
    root->left = buildTree(arr, s, mid-1);
    root->right = buildTree(arr, mid+1, e);

    return root;
}

int main(){
    int n;
    cin>>n;
    int inorder[n];
    ip(inorder, n);
    int l,h;
    cin>>l>>h;
    TreeNode *root=buildTree(inorder, 0, n-1);
    int ct=0;
    countSubtree(root, l, h, ct);
    cout<<ct<<endl;
    return 0;
}