// https://practice.geeksforgeeks.org/problems/check-for-bst/1/?track=PC-W6-BST&batchId=154
#include<iostream>
#include<vector>
#include<climits>
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

bool check(Node* root, long long mx=LLONG_MAX, long long mi=LLONG_MIN) {
    if(root==NULL)return true;
    
    return (root->data>mi and root->data<mx) and check(root->left, root->data, mi) and check(root->right, mx, root->data);
}
// return true if the given tree is a BST, else return false
bool isBST(Node* root) {
    if(root==NULL)return true;
    
    return check(root);
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