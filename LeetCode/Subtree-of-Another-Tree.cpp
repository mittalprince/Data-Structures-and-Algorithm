//https://leetcode.com/problems/subtree-of-another-tree/
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

bool isSubtree(TreeNode* s, TreeNode* t) {

    if(s == NULL)return false;

    if(sameTree(s,t))return true;

    bool leftCall = isSubtree(s->left, t);
    bool rightCall = isSubtree(s->right, t);

    return leftCall or rightCall;
}

bool sameTree(TreeNode * s, TreeNode * t){
    if(s == NULL and t == NULL)return true;

    if(s == NULL or t == NULL)return false;

    if(s->val != t->val)return false;

    bool leftSameTree = sameTree(s->left,t->left);
    bool rightSameTree = sameTree(s->right,t->right);

    return leftSameTree and rightSameTree;
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