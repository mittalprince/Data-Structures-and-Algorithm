// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
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

class Pair{
    public:
    int mx, mi, sum;
    bool isBST;

    Pair(){
        mx=INT_MIN, mi=INT_MAX, sum=0;
        isBST=true;
    }
};

Pair solve(TreeNode *root){
    Pair p;
    if(root==NULL)return p;

    if(!root->left and !root->right){
        p.mx = root->val, p.mi=root->val, p.sum=root->val;
        p.isBST=true;
        ans = max(ans, root->val);
        return p;
    }

    Pair left = solve(root->left);
    Pair right = solve(root->right);

    if(root->val>left.mx and root->val<right.mi and left.isBST and right.isBST){
        p.isBST=true;
        p.sum = root->val+left.sum+right.sum;
        ans = max(ans, p.sum);
        p.mx = max(root->val, max(left.mx, right.mx));
        p.mi = min(root->val, min(left.mi, right.mi));
    }
    else{
        p.isBST=false;  
    }
    return p;
}

int maxSumBST(TreeNode* root) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ans=0;
    Pair p = solve(root);
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