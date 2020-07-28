// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1/?track=PC-W6-BST&batchId=154
#include<iostream>
#include<vector>
#include<map>
#include<queue>
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

void leftView(Node *root){
   // Your Code here
   
   if(root==NULL)return;
   
   queue<Node*>q;
   q.push(root);
   
   
   while(!q.empty()){
       Node *prev=NULL;
       int size=q.size();
       for(int i=0; i<size; i++){
           Node *top = q.front();
           q.pop();
           if(!prev)prev = top;
           if(top->left)q.push(top->left);
           if(top->right)q.push(top->right);
       }
       cout<<prev->data<<" ";
   }
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