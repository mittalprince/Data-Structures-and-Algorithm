// https://leetcode.com/problems/cousins-in-binary-tree-ii/
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
    TreeNode *left, *right;

    TreeNode():val(0),left(NULL),right(NULL){};
};

TreeNode* replaceValueInTree(TreeNode* root) {
    if (!root) return nullptr;

    queue<TreeNode*> q;
    int prev = root->val;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        int curr = 0;

        while (size > 0) {
            TreeNode* temp = q.front();
            q.pop();

            int leftRight = (temp->left ? temp->left->val : 0) + (temp->right ? temp->right->val : 0);

            if (temp->left) {
                temp->left->val = leftRight;
                q.push(temp->left);
            }

            if (temp->right) {
                temp->right->val = leftRight;
                q.push(temp->right);
            }

            curr += leftRight;
            temp->val = prev - temp->val;
            size--;
        }

        prev = curr;
    }

    return root;
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