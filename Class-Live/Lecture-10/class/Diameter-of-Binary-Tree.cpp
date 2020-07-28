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

int helper(TreeNode *root, int &dia){
    if(root==NULL) return 0;

    int left = helper(root->left, dia);
    int right = helper(root->right, dia);

    dia = max(dia, left+right);
    return max(left, right)+1;
}
int diameterOfBinaryTree(TreeNode* root) {
    if(root==NULL|| !root->left&&!root->right) return 0;
    int dia=1;
    helper(root, dia);
    return dia;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}