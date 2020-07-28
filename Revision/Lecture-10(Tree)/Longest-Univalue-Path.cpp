// https://leetcode.com/problems/longest-univalue-path/
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

int ans=0;
int helper(TreeNode *root){
    if(!root)
        return 0;
    int left = helper(root->left);
    int right = helper(root->right);

    int arrowleft = 0,arrowright = 0;

    if(root->left && root->val == root->left->val)
        arrowleft += left + 1;

    if(root->right && root->val == root->right->val)
        arrowright += right+1;

    ans = max(ans,arrowleft+arrowright);
    return max(arrowleft,arrowright);
}

int longestUnivaluePath(TreeNode* root) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(root==NULL)return 0;

    ans=0;
    helper(root);
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