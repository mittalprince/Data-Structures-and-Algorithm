// https://leetcode.com/problems/minimum-absolute-difference-in-bst/
#include<iostream>
#include<vector>
#include<climits>
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

void solve(TreeNode *root, int &ans, int &pre){
    if(root==NULL)return;

    solve(root->left, ans, pre);

    if(pre != -1 and (root->val-pre)<ans){
        ans = (root->val-pre);
    }
    pre = root->val;
    solve(root->right, ans, pre);
}

int getMinimumDifference(TreeNode* root) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(root==NULL)return 0;
    int prev=-1;
    int ans=INT_MAX;

    solve(root, ans, prev);
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