// https://hack.codingblocks.com/app/practice/2/125/problem
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

class node{
    public:
    int data;
    node *left, *right;

    node(int d):data(d),left(NULL),right(NULL){}
};

node *buildTreeFromArr(int arr[], int s, int e){
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) >> 1;
    node *root = new node(arr[mid]);
    root->left = buildTreeFromArr(arr, s, mid - 1);
    root->right = buildTreeFromArr(arr, mid + 1, e);

    return root;
}

void traversal(node *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    traversal(root->left);
    traversal(root->right);
}

void replaceNodeData(node *root){
    static int sum=0;
    if(root==NULL)return;
    replaceNodeData(root->right);
    sum += root->data;
    root->data = sum;
    replaceNodeData(root->left);
}

void helper(){
    int n,data;
    cin>>n;
    int arr[n];
    node *root = NULL;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    root = buildTreeFromArr(arr, 0, n-1);
    replaceNodeData(root);
    traversal(root);
    cout<<endl;
}

int main(){
    helper();
}   