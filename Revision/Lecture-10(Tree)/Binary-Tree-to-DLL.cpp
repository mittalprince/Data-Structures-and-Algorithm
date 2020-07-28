// https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1
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

void solve(Node *root, Node *&head, Node *&prev){
    if(root==NULL)return;
    
    solve(root->left, head, prev);
    
    if(prev==NULL)head=root;
    else{
        prev->right = root;
        root->left = prev;
    }
    prev = root;
    
    solve(root->right, head, prev);
}

Node * bToDLL(Node *root){
    if(root==NULL)return root;
    
    Node *prev=NULL, *head=NULL;
    solve(root, head, prev);
    
    return head;
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