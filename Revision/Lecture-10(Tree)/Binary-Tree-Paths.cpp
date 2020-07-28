// https://leetcode.com/problems/binary-tree-paths/
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

void check(TreeNode *root, vector<string> &ans, vector<int> &temp){
    if(root==NULL) return;
    temp.push_back(root->val);

    if(root->left==NULL && root->right==NULL){
        string a="";
        for(auto i: temp){
            a += to_string(i)+"->";
        }
        if(a != ""){
            a.pop_back();a.pop_back();
            ans.push_back(a);
        } 
    }

    check(root->left, ans, temp);
    check(root->right, ans, temp);
    temp.pop_back();
}
vector<string> binaryTreePaths(TreeNode* root) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> ans;
    vector<int> temp;
    check(root, ans, temp);
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