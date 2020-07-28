// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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

TreeNode *solve(vector<int>& preorder, vector<int>& inorder, int &i, int s, int e){
    if(s>e)return NULL;

    int idx=s;
    while(idx<=e){
        if(preorder[i] == inorder[idx])break;
        idx++;
    }
    i++;
    TreeNode *root = new TreeNode(inorder[idx]);
    root->left = solve(preorder, inorder, i, s, idx-1);
    root->right = solve(preorder, inorder, i, idx+1, e);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=preorder.size();
    if(n==0)return NULL;

    int i=0;
    return solve(preorder, inorder, i, 0, n-1);
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