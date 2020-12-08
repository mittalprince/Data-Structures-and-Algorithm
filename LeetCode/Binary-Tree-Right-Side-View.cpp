//https://leetcode.com/problems/binary-tree-right-side-view/
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

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(NULL), right(NULL) {}

    TreeNode(int _val) : val(_val), left(NULL), right(NULL) {}

    TreeNode(int _val, TreeNode* _left, TreeNode* _right)
        : val(_val), left(_left), right(_right) {}
};

void helper(TreeNode *root, int level, int& max_level, vector<int> &ans){
    if(root==NULL) return;

    if(max_level<level){
        max_level=level;
        ans.push_back(root->val);
    }
    helper(root->right, level+1, max_level, ans);
    helper(root->left, level+1, max_level, ans);
}
vector<int> rightSideView(TreeNode* root) {
    vector<int>ans;
    int max_level=-1, level=0;
    helper(root, level, max_level, ans);
    return ans;
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