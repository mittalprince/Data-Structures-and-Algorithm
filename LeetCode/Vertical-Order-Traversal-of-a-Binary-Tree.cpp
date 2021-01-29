// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
#include<iostream>
#include<vector>
#include<map>
#include<set>
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
    TreeNode() : val(0), left(nullptr), right(nullptr){} 
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}                                                                                                                                                                          
};

map<int, set<pair<int, int>>> m;

void solve(TreeNode *root, int hd, int level){
    if (root == NULL){
        return;
    }
    m[hd].insert({level, root->val});
    solve(root->left, hd - 1, level + 1);
    solve(root->right, hd + 1, level + 1);
}

vector<vector<int>> verticalTraversal(TreeNode *root){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (root == NULL)
        return {};

    m.clear();
    solve(root, 0, 0);

    vector<vector<int>> ans;
    for (auto it : m){
        vector<int> t;
        for (auto i : it.second){
            t.push_back(i.second);
        }
        ans.push_back(t);
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