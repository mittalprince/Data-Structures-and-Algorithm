// https://leetcode.com/problems/path-sum-iii/
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

int pathSum(TreeNode* root, int sum) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<int, int> mp;
    mp[0] = 1;
    int res = 0;

    dfs(root, sum, mp, res, 0);

    return res;
}

void dfs(TreeNode* root, int sum, unordered_map<int, int>& mp, int& res, int preSum) {
    if (root == NULL) return;
    preSum += root->val;
    if (mp.count(preSum - sum) != 0) {
        res += mp[preSum - sum];
    }

    mp[preSum]++;
    dfs(root->left, sum, mp, res, preSum);
    dfs(root->right, sum, mp, res, preSum);
    mp[preSum]--;
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