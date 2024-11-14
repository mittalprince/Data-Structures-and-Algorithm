// https://leetcode.ca/2016-11-30-366-Find-Leaves-of-Binary-Tree/
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> res;
    TreeNode* prev = new TreeNode(0, root, nullptr);
    while (prev->left) {
        vector<int> t;
        dfs(prev->left, prev, t);
        res.push_back(t);
    }
    return res;
}

void dfs(TreeNode* root, TreeNode* prev, vector<int>& t) {
    if (!root) return;
    if (!root->left && !root->right) {
        t.push_back(root->val);
        if (prev->left == root)
            prev->left = nullptr;
        else
            prev->right = nullptr;
    }
    dfs(root->left, root, t);
    dfs(root->right, root, t);
}

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}