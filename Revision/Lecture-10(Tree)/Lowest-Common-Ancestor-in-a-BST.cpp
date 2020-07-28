// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1/?track=PC-W6-BST&batchId=154
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

class Node{
public:
    int data;
    Node *left, *right;
    Node():data(0),left(NULL),right(NULL){}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

Node* LCA(Node *root, int n1, int n2){
    if(root== NULL)return NULL;
    
    if(root->data > n1 and root->data >n2){
        return LCA(root->left, n1, n2);
    }
    if(root->data <n1 and root->data <n2){
        return LCA(root->right, n1, n2);
    }
    return root;
   //Your code here
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