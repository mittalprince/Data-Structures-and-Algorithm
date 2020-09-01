// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
#include<iostream>
#include<vector>
#include<queue>
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
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxLevelSum(TreeNode* root) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int max = root->val, n = 1, tmp = 0, currlvl = 0, lvl = 1;
    queue<TreeNode*> q;
    TreeNode* t;

    q.push(root);

    while(!q.empty()) {
        tmp = 0;
        ++currlvl;

        for(n = q.size(); n > 0; --n) {
            t = q.front();
            q.pop();
            tmp += t->val;
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }

        if(tmp > max) {
            max = tmp;
            lvl = currlvl;
        }
    }

    // this line reduce 40 MB memory usage??
    root->left = root->right = nullptr;
    return lvl;
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