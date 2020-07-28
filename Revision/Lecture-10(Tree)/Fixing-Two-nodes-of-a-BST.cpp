// https://practice.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1/?track=PC-W6-BST&batchId=154
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

void solve(Node *root, vector<Node*>&v, Node *&prev){
    if(root==NULL)return;
    
    solve(root->left, v, prev);
    
    if(prev and root->data < prev->data){
        if(v.empty()){
            v.push_back(prev);
            v.push_back(root);
        }
        else{
            v[1]=root;
        }
    }
    prev=root;
    solve(root->right, v, prev);
}

Node *correctBST(Node* root ){
    if(root==NULL){
        return root; 
    }
    vector<Node*>v;
    Node *prev=NULL;
    
    solve(root, v, prev);
    
    int t = v[0]->data;
    v[0]->data = v[1]->data;
    v[1]->data = t;
    
    return root;
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