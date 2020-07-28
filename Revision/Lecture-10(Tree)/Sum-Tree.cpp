// https://practice.geeksforgeeks.org/problems/sum-tree/1/
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

bool ans=true;

int solve(Node *root){
    if(root==NULL || !ans)return 0;
    
    if(!root->left and !root->right)return root->data;
    
    int left = solve(root->left);
    int right = solve(root->right);
    
    if(root->data != left+right)ans=false;
    return root->data+left+right;
}
// Should return true if tree is Sum Tree, else false
bool isSumTree(Node* root)
{
     if(root==NULL)return true;
     ans=true;
     solve(root);
     return ans;
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