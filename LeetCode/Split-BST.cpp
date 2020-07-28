// https://massivealgorithms.blogspot.com/2019/02/leetcode776-split-bst.html
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

vector<TreeNode*> splitBST(TreeNode* root, int V) {
    if (root == NULL) {
        return vector<TreeNode*>(2, NULL);
    } else if (root->val <= V) {
        auto lr = splitBST(root->right, V);
        root->right = lr[0];
        lr[0] = root;
        return lr;
    } else {
        auto lr = splitBST(root->left, V);
        root->left = lr[1];
        lr[1] = root;
        return lr;
    }
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