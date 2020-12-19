//https://leetcode.com/problems/find-mode-in-binary-search-tree/
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

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int mx_ct=0, ct=0;
vector<int>ans;

void inorder(TreeNode *root, TreeNode *&prev, bool flag){
    if(root==NULL)return;

    inorder(root->left, prev, flag);

    if(prev and prev->val == root->val){
        ct++;
    }
    else ct=1;
    if(flag){
        mx_ct = max(mx_ct, ct);
    }
    else if(ct==mx_ct){
        ans.push_back(root->val);
    }
    prev=root;
    inorder(root->right, prev, flag);
}

vector<int> findMode(TreeNode* root) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    TreeNode *prev=NULL;

    inorder(root, prev, true);
    ct=0;

    prev=NULL;
    inorder(root, prev, false);
    return ans;
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