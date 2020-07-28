// https://hack.codingblocks.com/app/practice/2/8/problem
#include<iostream>
#include<climits>
#include<vector>
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

    TreeNode(int v):val(v),left(NULL),right(NULL){}
};

class Pair{
    public:
    int sz,mx,mi;
    bool isBST;

    Pair(){
        sz=0,mx=INT_MIN,mi=INT_MAX;
        isBST=true;
    }
};

Pair largestBST(TreeNode *root){
    Pair p;
    if(root == NULL){
        return p;
    }

    if(!root->left and !root->right){
        p.sz=1;
        p.mx=root->val;
        p.mi=root->val;
        p.isBST=true;
        return p;
    }

    Pair left = largestBST(root->left);
    Pair right = largestBST(root->right);

    if(root->val > left.mx and root->val < right.mi and left.isBST and right.isBST){
        p.sz = left.sz+right.sz+1;
        p.isBST=true;
        p.mx = max(root->val, max(left.mx, right.mx));
        p.mi = min(root->val, min(left.mi, right.mi));
    }
    else{
        p.sz=max(right.sz, left.sz);
        p.isBST=false;
    }
    return p;
}

TreeNode* buildBST(vector<int>&preorder, vector<int>&inorder, int &i, int s, int e){
    if(s>e){
        return NULL;
    }
    
    int idx=s;
    while(idx<=e){
        if(preorder[i]==inorder[idx])break;
        idx++;
    }
    i++;
    TreeNode *root = new TreeNode(inorder[idx]);
    root->left = buildBST(preorder, inorder, i, s, idx-1);
    root->right = buildBST(preorder, inorder, i, idx+1, e);

    return root;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> preorder(n), inorder(n);

    ip(preorder, n);
    ip(inorder, n);
    int i=0;
    TreeNode *root = buildBST(preorder, inorder, i, 0, n-1);
    
    Pair p = largestBST(root);
    cout<<p.sz<<endl;
    return 0;
}