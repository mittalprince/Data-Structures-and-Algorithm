//https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
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

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int solve(TreeNode *root, int currMax, int currMin){
    if(root==NULL){
        return currMax-currMin;
    }
    currMax = max(currMax, root->val);
    currMin = min(currMin, root->val);

    int l = solve(root->left, currMax, currMin);
    int r = solve(root->right, currMax, currMin);
    return max(l,r);
}

int maxAncestorDiff(TreeNode* root) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int currMax=INT_MIN, currMin=INT_MAX;
    return solve(root, currMax, currMin);
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