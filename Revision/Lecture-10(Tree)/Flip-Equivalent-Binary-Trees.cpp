// https://leetcode.com/problems/flip-equivalent-binary-trees/
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

bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    if(!root1 and !root2)return true;
    if(!root1 or !root2)return false;

    if(root1->val != root2->val)return false;

    return (flipEquiv(root1->left, root2->left) and flipEquiv(root1->right, root2->right)) ||
           (flipEquiv(root1->right, root2->left) and flipEquiv(root1->left, root2->right)); 
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