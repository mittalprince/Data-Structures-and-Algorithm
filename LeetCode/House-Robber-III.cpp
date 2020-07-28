// https://leetcode.com/problems/house-robber-iii/
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

int solve(TreeNode *root, int &left, int &right){
    if(root==NULL)return 0;

    int ll=0, lr=0, rl=0, rr=0;
    left = solve(root->left, ll, lr);
    right = solve(root->right, rl, rr);

    return max(root->val+ll+lr+rl+rr, left+right);
}
int rob(TreeNode* root) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int left=0, right=0;
    return solve(root, left, right);
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