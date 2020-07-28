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

vector<int>ans; 

void kdistNode(TreeNode *root, int k){
    if(root==NULL) return;
    if(k==0){
        ans.push_back(root->val);
        return;
    }
    kdistNode(root->left, k-1);
    kdistNode(root->right, k-1);
}

int helper(TreeNode *root, TreeNode *target, int k){
    if(root==NULL) return -1;

    if(root==target){
        kdistNode(root, k);
        return 1;
    }

    int left = helper(root->left, target, k);
    if(left != -1){
        if(left == k){
            ans.push_back(root->val);
        }
        else{
            kdistNode(root->right, k-left-1);
        }
        return left+1;
    }

    int right = helper(root->right, target, k);
    if(right != -1){
        if(right == k){
            ans.push_back(root->val);
        }
        else{
            kdistNode(root->left, k-right-1);
        }
        return right+1;
    }
    return -1;
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    ans.clear();
    helper(root, target, k);
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}