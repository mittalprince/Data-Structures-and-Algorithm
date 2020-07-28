#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class Node{
    public:
    int val;
    Node *left, *right;

    Node():val(0),left(NULL),right(NULL){}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorder(Node *root, Node *&head, Node *&prev){
    if(root==NULL) return;
    inorder(root->left, head, prev);
    if(head==NULL){
        head=root;
        prev=root;
    }
    else{
        prev->right=root;
        root->left=prev;
        prev=root;
    }
    inorder(root->right, head, prev);
}

Node* treeToDoublyList(Node *root){
    if(root==NULL) return root;
    Node *head=NULL, *prev=NULL;
    inorder(root, head, prev);
    head->left=prev;
    prev->right=head;
    return head;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}