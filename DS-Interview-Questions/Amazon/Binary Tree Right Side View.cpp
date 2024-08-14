// https://leetcode.com/problems/binary-tree-right-side-view/
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

void helper(TreeNode* root, int& maxLevel, int level, vector<int>& ans){
    if(root == NULL) return;
    if (maxLevel < level){
        maxLevel = level;
        ans.push_back(root->val);
    }
    helper(root->right, maxLevel, level+1, ans);
    helper(root->left, maxLevel, level+1, ans);
}
vector<int> rightSideView(TreeNode* root) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (root==NULL) return {};
    int maxLevel=-1;
    vector<int>ans;
    helper(root, maxLevel, 0, ans);
    return ans;
}

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}