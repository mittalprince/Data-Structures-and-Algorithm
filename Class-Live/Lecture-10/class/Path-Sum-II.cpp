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

void findPath(TreeNode *root, int sum, vector<int>temp, vector<vector<int>>&ans){
    if(root==NULL) return;
    temp.push_back(root->val);

    if(!root->left && !root->right && root->val == sum){
        ans.push_back(temp);
    }
    else{
        findPath(root->left, sum-root->val, temp, ans);
        findPath(root->right, sum-root->val, temp, ans);
    }
    temp.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>>ans;
    vector<int>temp;

    findPath(root, sum, temp, ans);
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}