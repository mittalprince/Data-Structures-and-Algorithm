// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
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

void recurssiveSumFinder(TreeNode *root, int &ans)
{
    if(!root)
        return;

    if(root->val%2 == 0)
    {
        if(root->left && root->left->left)
            ans += root->left->left->val;

        if(root->left && root->left->right)
            ans += root->left->right->val;

        if(root->right && root->right->left)
            ans += root->right->left->val;

        if(root->right && root->right->right)
            ans += root->right->right->val;
    }

    recurssiveSumFinder(root->left, ans);
    recurssiveSumFinder(root->right, ans);
}

int sumEvenGrandparent(TreeNode* root) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(root==NULL)return 0;
    int ans=0;
    recurssiveSumFinder(root, ans);

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