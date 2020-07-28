// https://leetcode.com/problems/path-sum-ii/
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

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> res;
    vector<int> path;
    helper(root, sum, path, res);
    return res;
}

void helper(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& res) {
    if (root == NULL) {
        return;
    }
    path.push_back(root->val);
    if (root->left == NULL && root->right == NULL) {
        if (sum - root->val == 0) {
            res.push_back(path);
        } 
    }
    helper(root->left, sum - root->val, path, res);
    helper(root->right, sum - root->val, path, res);
    path.pop_back();
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