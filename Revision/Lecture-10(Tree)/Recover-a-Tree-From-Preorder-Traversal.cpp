// https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
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

TreeNode* solve(string s, int &i, int &level, int currLevel){
    if(i==s.length())return NULL;

    int n=0;
    while(i<s.length() and s[i] != '-'){
        n = n*10+(s[i]-'0');
        i++;
    }

    TreeNode *root = new TreeNode(n);
    level=0;

    while(i<s.length() and s[i] == '-'){
        level++;
        i++;
    }

    if(level<=currLevel)return root;
    root->left = solve(s,i,level,currLevel+1);

    if(level<=currLevel)return root;
    root->right = solve(s,i,level,currLevel+1);

    return root;
}
TreeNode* recoverFromPreorder(string s) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int level=0, i=0;
    return solve(s, i, level, 0);
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