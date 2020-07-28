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
    string tree2str(TreeNode* root) {
        if(root==NULL) return "";
        
        if(!root->left && !root->right) return to_string(root->val);
        
        string left = tree2str(root->left);
        string ans = to_string(root->val)+"("+left+")";
        if(root->right){
            string right = tree2str(root->right);
            ans += "("+right+")";
        }
        
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}