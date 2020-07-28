// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
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

Node* solve(Node* root, int n1, int n2, bool &v1, bool &v2){
    if(root==NULL)return NULL;
    
    if(root->data == n1){
        v1=true;
        return root;
    }
    if(root->data == n2){
        v2=true;
        return root;
    }
    
    Node *left = solve(root->left, n1, n2, v1, v2);
    Node *right = solve(root->right, n1, n2, v1, v2);
    
    if(left and right){
        return root;
    }
    return left?left:right;
}

bool find(Node *root, int val){
    if(root==NULL)return false;
    if(root->data == val)return true;
    
    return find(root->left, val) || find(root->right, val);
}
Node* lca(Node* root ,int n1 ,int n2 ){
    if(root==NULL)return NULL;
    
    bool v1=false, v2=false;
    Node *l = solve(root, n1, n2, v1, v2);
    if(v1 and v2 or v1 and find(l,n2) or v2 and find(l,n1))return l;
    return NULL;
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