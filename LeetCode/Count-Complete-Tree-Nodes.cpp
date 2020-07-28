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
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}                                                                                                                                                                                               *
};

int leftHeight(TreeNode *root){
    if(root==NULL)return 0;
    return 1+leftHeight(root->left);
}
int rightHeight(TreeNode *root){
    if(root==NULL)return 0;
    return 1+rightHeight(root->right);
}
int countNodes(TreeNode* root) {
    int lH = leftHeight(root);
    int rH = rightHeight(root);
    if(lH==rH){
        return (1<<lH)-1;
    }
    else{
        return 1+countNodes(root->left)+countNodes(root->right);
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