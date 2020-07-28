#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class TreeNode{
    public:
    int val;
    TreeNode *left, *right;

    TreeNode():val(0),left(NULL),right(NULL){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}