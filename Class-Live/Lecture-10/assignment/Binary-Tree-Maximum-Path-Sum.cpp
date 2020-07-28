#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
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
};

/*
1. for single node, the ans is node val itself
2. for leaf nodes, the maxSum is leaf node val itself, so if root is null return 0;
3. for a tree with all -ve values the best path is node with largest val in whole tree, as addtion to this we decr the sum
4. Using above fact we take max(left_tree_sum, 0); and simillary for right tree
5. for a particular node(x) its max path sum include, it left,right,root, So we cal curr_sum = root->val+left+right
   and update max_sum if is lesser
6. Now for its parent(y), this node parent can take path of either its children(x), x->val and x->left tree path or x->right tree path
   so we just return root->val+max(left, right)
   
*/
class Solution {
public:
    int maxSum(TreeNode* root, int &max_sum){
        if(root==NULL)return 0;
        
        int left = max(maxSum(root->left, max_sum), 0);
        int right = max(maxSum(root->right, max_sum), 0);
        
        int curr_sum = root->val+left+right;
        
        max_sum = max(curr_sum, max_sum);
        return root->val+max(left, right);
    }
    
    int maxPathSum(TreeNode* root) {
        int max_sum=INT_MIN;
        maxSum(root, max_sum);
        
        return max_sum;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}