// https://hack.codingblocks.com/app/practice/2/340/problem
#include<iostream>
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

    TreeNode():val(0),left(NULL),right(NULL){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(vector<int>&inorder, int s, int e){
    if(s>e)return NULL;

    int mid = (s+e)/2;
    TreeNode *root = new TreeNode(inorder[mid]);
    root->left = buildTree(inorder, s, mid-1);
    root->right = buildTree(inorder, mid+1, e);

    return root;
}

bool countNodes(TreeNode *root, int l, int r, int &res){
    if(root==NULL)return true;

    bool left = countNodes(root->left, l, r, res);
    bool right = countNodes(root->right, l, r, res);

    if(root->val>=l and root->val<=r and left and right){
        res++;
        return true;
    }
    return false;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    ip(arr, n);

    int l,r;
    cin>>l>>r;

    TreeNode *root = buildTree(arr, 0, n-1);
    int res=0;
    countNodes(root, l, r, res);
    cout<<res<<endl;
    return 0;
}