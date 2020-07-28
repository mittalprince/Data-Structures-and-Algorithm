// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
#include<iostream>
#include<vector>
#include<unordered_map>
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

TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<int, int> m;
    for (int i = 0; i < post.size(); ++i) m[post[i]] = i;
    return helper(pre, 0, (int)pre.size() - 1, post, 0, (int)post.size() - 1, m);
}
TreeNode* helper(vector<int>& pre, int preL, int preR, vector<int>& post, int postL, int postR, unordered_map<int, int>& m) {
    if (preL > preR || postL > postR) return nullptr;
    TreeNode *node = new TreeNode(pre[preL]);
    if (preL == preR) return node;
    int idx = m[pre[preL + 1]], len = (idx - postL) + 1;
    node->left = helper(pre, preL + 1, preL + len, post, postL, idx, m);
    node->right = helper(pre, preL + 1 + len, preR, post, idx + 1, postR - 1, m);
    return node;
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