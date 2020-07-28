// https://leetcode.com/problems/binary-tree-postorder-traversal/
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
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

vector<int> postorderTraversal(TreeNode* root) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(root==NULL)return {};
    vector<int>ans;

    stack<TreeNode*>s;
    s.push(root);

    while(!s.empty()){
        TreeNode *top = s.top();
        s.pop();

        ans.push_back(top->val);
        if(top->left){
            s.push(top->left);
        }
        if(top->right){
            s.push(top->right);
        }
    }

    reverse(ans.begin(), ans.end());
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