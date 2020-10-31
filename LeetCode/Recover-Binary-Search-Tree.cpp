//https://leetcode.com/problems/recover-binary-search-tree/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
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

    TreeNode(int v):val(v),left(NULL),right(NULL){}
};

void inorder(TreeNode *root, TreeNode *&prev, vector<TreeNode*>&ans){
    if(root==NULL)return ;

    inorder(root->left, prev, ans);

    if(prev && root->val < prev->val){
        if(ans.empty()){
            ans.push_back(prev);
            ans.push_back(root);
        }
        else ans.push_back(root);
    }
    prev=root;
    inorder(root->right, prev, ans);
}

void recoverTree(TreeNode* root) {
    vector<TreeNode*>ans;
    TreeNode *prev=NULL;

    inorder(root, prev, ans);

    if(ans.size()>2){
        ans.erase(ans.begin()+1);
    }

    int temp = ans[0]->val;
    ans[0]->val = ans[1]->val;
    ans[1]->val = temp;

    return;
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