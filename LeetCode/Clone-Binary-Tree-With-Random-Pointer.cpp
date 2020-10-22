//https://www.lintcode.com/problem/clone-binary-tree/description
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

class Node {
public:
    int val;
    Node *left, *right, *random;
    Node(int val) {
       this->val = val;
       this->left = this->right = this->random = NULL;
    }
};

Node* copyLeftRightNode(Node *root){
    if(root==NULL)return root;

    Node *left = root->left;
    root->left = new Node(root->val);
    root->left->left = left;
    
    if(left){
        left->left = copyLeftRightNode(left);
    }
    root->left->right = copyLeftRightNode(root->right);
    return root->left;
}

void copyRandomNode(Node* root, Node* cloneNode){
    if(root==NULL)return;
    if(root->random){
        cloneNode->random=root->random->left;
    }

    if(root->left and cloneNode->left){
        copyRandomNode(root->left->left, cloneNode->left->left);
    }
    copyRandomNode(root->right, cloneNode->right);
}

void restoreTreeLeftNode(Node *root, Node *cloneNode){
    if(root==NULL)return;
    if(cloneNode->left){
        Node *left = cloneNode->left->left;
        root->left = root->left->left;
        cloneNode->left = left;
    }
    else root->left = NULL;

    restoreTreeLeftNode(root->left, cloneNode->left);
    restoreTreeLeftNode(root->right, cloneNode->right);
}

Node* cloneTree(Node* root) {
    if(root==NULL)return root;

    Node *cloneNode = copyLeftRightNode(root);
    copyRandomNode(root, cloneNode);
    restoreTreeLeftNode(root, cloneNode);
    return cloneNode;
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