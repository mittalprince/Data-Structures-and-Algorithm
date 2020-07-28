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

TreeNode* helper(string s, int &i, int &level, int currLevel){
    if(i == s.length()) return NULL;

    long long n=0;
    while(i<s.length() && s[i] != '-'){
        n = n*10+(s[i++]-'0');
    }

    TreeNode *root = new TreeNode(n);

    level=0;
    while(i<s.length() && s[i] == '-'){
        level++;
        i++;
    }

    if(level<=currLevel) return root;
    root->left = helper(s, i, level, currLevel+1);

    if(level<=currLevel) return root;
    root->right = helper(s, i, level, currLevel+1);

    return root;
}

TreeNode* recoverFromPreorder(string s, int currLevel=0) {
    int level=0, i=0;
    return helper(s, i, level, 0);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}