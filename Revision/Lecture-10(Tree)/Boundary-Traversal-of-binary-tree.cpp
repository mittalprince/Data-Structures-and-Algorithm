// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
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

struct Node{
    int data;
    Node* left, * right;
};

void printLeaves(Node *root){
    if(root==NULL) return;
    
    
    if(!root->left && !root->right){
        cout<<root->data<<" ";
        return;
    }
    printLeaves(root->left);
    printLeaves(root->right);
}

void printLeftBoundary(Node *root){
    if(root==NULL) return;
    
    if(root->left){
        cout<<root->data<<" ";
        printLeftBoundary(root->left);
    }
    else if(root->right){
        cout<<root->data<<" ";
        printLeftBoundary(root->right);
    }
}

void printRightBoundary(Node *root){
    if(root==NULL) return;
    
    if(root->right){
        printRightBoundary(root->right);
        cout<<root->data<<" ";
    }
    else if(root->left){
        printRightBoundary(root->left);
        cout<<root->data<<" ";
    }
}
void printBoundary(Node *root)
{
     if(root==NULL) return;
     cout<<root->data<<" ";
     printLeftBoundary(root->left);
     printLeaves(root->left);
     printLeaves(root->right);
     printRightBoundary(root->right);
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