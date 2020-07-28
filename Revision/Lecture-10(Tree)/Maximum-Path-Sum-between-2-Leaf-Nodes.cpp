// https://practice.geeksforgeeks.org/problems/maximum-path-sum/1/?track=PC-W6-BST&batchId=154
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

int ans;

int solve(Node *root){
    if(root==NULL)return INT_MIN;
    if(!root->left and !root->right)return root->data;
    
    int left = solve(root->left);
    int right = solve(root->right);
    
    int m = max(left, right);
    if(root->left and root->right)
    ans = max(ans, root->data+left+right);
    
    return m+root->data;
}
int maxPathSum(Node* root)
{ 
    if(root==NULL)return 0;
    ans = INT_MIN;
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