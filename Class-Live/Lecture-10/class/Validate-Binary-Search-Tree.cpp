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

bool isValidBST(TreeNode* root, long long mx=LLONG_MAX, long long mi=LLONG_MIN) {
    // return check(root, LLONG_MAX, LLONG_MIN);;
    if(root==NULL) return true;

    return (root->val>mi && root->val<mx && isValidBST(root->left, root->val, mi) && isValidBST(root->right, mx, root->val));
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}