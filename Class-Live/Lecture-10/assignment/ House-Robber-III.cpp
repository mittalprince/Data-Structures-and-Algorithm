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

class Solution {
public:
    int helper(TreeNode *root, int &left, int &right){
        if(root==NULL) return 0;
        
        int left_left=0, left_right=0, right_right=0, right_left=0;
        left = helper(root->left, left_left, left_right);
        right = helper(root->right, right_left, right_right);
        
        return max(root->val+left_left+left_right+right_left+right_right, left+right);
    }
    
    int rob(TreeNode* root) {
        int left=0, right=0;
        return helper(root, left, right);
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}