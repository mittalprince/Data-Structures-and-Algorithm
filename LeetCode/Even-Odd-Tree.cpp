// https://leetcode.com/problems/even-odd-tree/
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int ok = 1;
vector<int> v[100005];
void dfs(TreeNode *rt, int dep) {
    if(rt->val%2 != dep%2) ok = 0;
    v[dep].push_back(rt->val);
    if(rt->left) dfs(rt->left, dep+1);
    if(rt->right) dfs(rt->right, dep+1);
}

bool isEvenOddTree(TreeNode* root) {
    if(root==NULL)return 1;
    dfs(root, 1);

    if(!ok)return 0;

    for(int i=1; ; i++){
        if(v[i].empty())break;
        for(int j=1; j<v[i].size(); j++){
            if(i&1){
                if(v[i][j]<=v[i][j-1])return 0;
            }
            else{
                if(v[i][j]>=v[i][j-1])return 0;
            }
        }
    }
    return 1;
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