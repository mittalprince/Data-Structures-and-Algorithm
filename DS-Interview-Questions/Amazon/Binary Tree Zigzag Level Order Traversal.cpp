// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(root==NULL)return {};
    vector<vector<int> >ans;

    stack<TreeNode*>s1, s2;
    s1.push(root);

    while(!s1.empty() or !s2.empty()){
        vector<int>t;
        while(!s1.empty()){
            TreeNode *top = s1.top();
            s1.pop();
            t.push_back(top->val);

            if(top->left)s2.push(top->left);
            if(top->right)s2.push(top->right);
        }

        if(!t.empty())ans.push_back(t);
        t.clear();

        while(!s2.empty()){
            TreeNode *top=s2.top();
            s2.pop();
            t.push_back(top->val);

            if(top->right){
                s1.push(top->right);
            }
            if(top->left){
                s1.push(top->left);
            }
        }
        if(!t.empty())ans.push_back(t);
    }

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