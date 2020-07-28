#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class TreeNode{
    public:
    int val;
    TreeNode *left, *right;

    TreeNode():val(0),left(NULL),right(NULL){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<TreeNode*> generateTrees(int n) {
    if (n==0){
        return {};
    }else{
        return trees(1, n);
    }
}

vector<TreeNode*> trees(int i, int j) {
    if (i>j) return {NULL};
    TreeNode* root;
    vector<TreeNode*> lefts, rights, res;
    for (int ind=i; ind<=j; ind++){
        lefts = trees(i, ind-1);
        rights = trees(ind+1, j);
        for (TreeNode* t1:lefts){
            for (TreeNode* t2:rights){
                root = new TreeNode(ind);
                root->left = t1;
                root->right = t2;
                res.push_back(root);
            }
        }
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}