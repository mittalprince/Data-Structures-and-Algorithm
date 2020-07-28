#include<iostream>
#include<vector>
#include<stack>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        
        stack<TreeNode*>s1, s2;
        
        s1.push(root);
        while(!s1.empty() || !s2.empty()){
            vector<int>temp;
            
            while(!s1.empty()){
                TreeNode *top=s1.top();
                temp.push_back(top->val);
                s1.pop();
                if(top->left){
                    s2.push(top->left);
                }
                if(top->right){
                    s2.push(top->right);
                }
            }
            if(!temp.empty()){
                ans.push_back(temp);
                temp.clear();
            }
            
            while(!s2.empty()){
                TreeNode *top=s2.top();
                temp.push_back(top->val);
                s2.pop();
                if(top->right){
                    s1.push(top->right);
                }
                if(top->left){
                    s1.push(top->left);
                }
            }
            
            if(!temp.empty()){
                ans.push_back(temp);
            }
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