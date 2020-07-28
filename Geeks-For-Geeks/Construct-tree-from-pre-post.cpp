// https://www.geeksforgeeks.org/full-and-complete-binary-tree-from-given-preorder-and-postorder-traversals/
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

int i;
TreeNode* solve(vector<int>&pre, vector<int>&post, int s, int e){
    if(i>=pre.size() or s>e){
        return NULL;
    }

    TreeNode *root = new TreeNode(pre[i]);
    i++;

    if(s==e)return root;
    int j;
    for(j=s; j<=e; j++){
        if(pre[i] == post[j])break;
    }

    if(j<=e){
        root->left = solve(pre, post, s, j);
        root->right = solve(pre, post, s+j, e);
    }
    return root;
}

TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    i=0;
    return solve(pre, post, 0, pre.size()-1);    
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