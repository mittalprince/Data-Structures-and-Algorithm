#include<iostream>
#include<vector>
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

map<TreeNode*, bool>m;
int camera;

void PlaceCamera(TreeNode *root, TreeNode *parent){
    if(root==NULL) return;

    PlaceCamera(root->left, root);
    PlaceCamera(root->right, root);

    if(parent == NULL && !m.count(root)|| !m.count(root->left) || !m.count(root->right)){
        camera++;
        m[parent]=m[root]=m[root->left]=m[root->right]=true;
    }

} 
int minCameraCover(TreeNode* root) {
    if(root==NULL) return 0;
    camera=0;
    m[NULL]=true;
    PlaceCamera(root, NULL);
    return camera;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}