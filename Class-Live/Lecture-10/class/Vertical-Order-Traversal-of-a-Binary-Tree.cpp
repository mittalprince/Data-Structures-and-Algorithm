#include<iostream>
#include<vector>
#include<set>
#include<map>
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

class Solution {
public:
    map<int, set<pair<int, int>>>m;
    
    void helper(TreeNode *root, int hd, int level){
        if(root==NULL) return;
        
        m[hd].insert({level, root->val});
        helper(root->left, hd-1, level+1);
        helper(root->right, hd+1, level+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        helper(root, 0, 0);
        vector<vector<int>>ans;
        
        for(auto it: m){
            vector<int>temp;
            for(auto i: it.second){
                temp.push_back(i.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}