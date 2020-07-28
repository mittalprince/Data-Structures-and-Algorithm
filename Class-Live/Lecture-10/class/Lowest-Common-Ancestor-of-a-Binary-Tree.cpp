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

class node{
    public:
    bool containP, containQ;
    TreeNode *n;
};

node* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL){
        return NULL;
    }
    
    node *left=LCA(root->left, p, q);
    if(left && left->n) return left;

    node *right=LCA(root->right, p, q);
    if(right && right->n) return right;

    node *x=new node();
    if(left && right){
        x->n = root;
        x->containP=x->containQ=true;
        return x;
    }

    if(root->val == p->val){
        x->containP=true;
        x->containQ = left?left->containQ:false || right?right->containQ:false;
        if(x->containQ && x->containP) x->n=root;
        return x;
    }
    if(root->val == q->val){
        x->containQ=true;
        x->containP = left?left->containP:false || right?right->containP:false;
        if(x->containQ && x->containP) x->n=root;
        return x;
    }

    if(left)return left;
    else if(right) return right;
    return NULL;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    node *ans=LCA(root, p, q);
    return ans->n;       
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}