// https://leetcode.com/problems/add-one-row-to-tree/
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

void solve(TreeNode *root, int d, int v){
    if(root==NULL)return;

    if(d==1){
        TreeNode *left=root->left, *right=root->right;
        root->left = new TreeNode(v);
        root->right = new TreeNode(v);

        root->left->left = left;
        root->right->right = right;
    }
    solve(root->left, d-1, v);
    solve(root->right, d-1, v);
}

TreeNode* addOneRow(TreeNode* root, int v, int d) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(d==1){
        TreeNode *t = new TreeNode(v);
        t->left=root;
        return t;
    }
    solve(root, d-1, v);
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