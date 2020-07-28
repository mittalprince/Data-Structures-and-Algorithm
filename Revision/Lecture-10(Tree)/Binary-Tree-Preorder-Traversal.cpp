// https://leetcode.com/problems/binary-tree-preorder-traversal/
#include<iostream>
#include<vector>
#include<stack>
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

vector<int> preorderTraversal(TreeNode* root) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(root==NULL)return{};

    vector<int>ans;

    stack<TreeNode*>q;
    TreeNode *curr = root;

    while(true){
        if(curr){
            ans.push_back(curr->val);
            q.push(curr);
            curr = curr->left;
        }
        else{
            if(q.empty())break;
            TreeNode *top =q.top();
            q.pop();
            curr = top->right;
        }
    }

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