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
    int helper(TreeNode *root, int &ans){
        if(root==NULL) return 0;
        
        int left=helper(root->left, ans);
        int right=helper(root->right, ans);
        int t=root->val+left+right-1;
        ans += abs(t);
        
        return t;
    }
    int distributeCoins(TreeNode* root) {
        int ans=0;
        helper(root, ans);
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}