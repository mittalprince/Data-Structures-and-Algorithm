// https://leetcode.com/problems/binary-tree-level-order-traversal/
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

vector<vector<int>> levelOrder(TreeNode* root) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int> >ans;

    if(root==NULL)return {};
    vector<int>t;

    queue<TreeNode*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        TreeNode *top = q.front();
        q.pop();

        if(top){
            t.push_back(top->val);
            if(top->left)q.push(top->left);
            if(top->right)q.push(top->right);
        }
        else{
            ans.push_back(t);
            t.clear();
            if(!q.empty())q.push(NULL);
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