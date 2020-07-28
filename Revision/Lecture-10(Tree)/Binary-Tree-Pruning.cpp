// https://leetcode.com/problems/binary-tree-pruning/
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

bool solve(TreeNode *root){
    if(root == NULL)return false;
    
    bool left = solve(root->left);
    bool right = solve(root->right);
    
    if(!left)root->left=NULL;
    if(!right)root->right=NULL;
    
    return root->val==1||left||right;
}
TreeNode* pruneTree(TreeNode* root) {
    
    bool ans = solve(root);
    if(!ans)root=NULL;
    
    return root;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}