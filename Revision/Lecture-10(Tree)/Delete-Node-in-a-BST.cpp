// https://leetcode.com/problems/delete-node-in-a-bst/
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

class TreeNode{
    public:
    int val;
    TreeNode *left, *right;

    TreeNode():val(0),left(NULL),right(NULL){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* deleteNode(TreeNode* root, int key) {
    if(root==NULL)return NULL;

    if(root->val >key){
        root->left = deleteNode(root->left, key);
        return root;
    }
    else if(root->val == key){
        if(!root->left and !root->right){
            delete root;
            return NULL;
        }
        if(root->left and !root->right){
            TreeNode *left = root->left;
            delete root;
            return left;
        }
        if(root->right and !root->left){
            TreeNode *right = root->right;
            delete root;
            return right;
        }

        TreeNode *replace = root->right;
        while(replace->left){
            replace = replace->left;
        }
        root->val = replace->val;
        root->right = deleteNode(root->right, replace->val);
        return root;
    }
    else{
        root->right = deleteNode(root->right, key);
        return root;
    }

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