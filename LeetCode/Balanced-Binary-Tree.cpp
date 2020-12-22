//https://leetcode.com/problems/balanced-binary-tree/
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

class Pair{
public:
int ht;
bool isBal;

Pair():ht(0),isBal(true){};
};

Pair checkBalanced(TreeNode *root){
    Pair p;
    if(root==NULL) return p;

    if(!root->left && !root->right){
        p.ht=1;
        p.isBal=true;
    }

    Pair left=checkBalanced(root->left);
    Pair right=checkBalanced(root->right);

    p.ht = max(left.ht, right.ht)+1;
    if(left.isBal && right.isBal && abs(left.ht-right.ht)<=1){
        p.isBal=true;
    }
    else p.isBal=false;
    return p;
}
bool isBalanced(TreeNode* root) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Pair temp=checkBalanced(root);
    return temp.isBal;

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