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

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        
        TreeNode *curr=root, *temp;
        
        while(curr){
            if(curr->left){
                temp=curr->left;
                while(temp->right){
                    temp=temp->right;
                }
                temp->right = curr->right;
                curr->right=curr->left;
                curr->left=NULL;   
            }
            curr=curr->right;
        }
        return;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}