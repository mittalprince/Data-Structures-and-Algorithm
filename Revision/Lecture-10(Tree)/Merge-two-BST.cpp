// https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1/?track=PC-W6-BST&batchId=154
#include<iostream>
#include<vector>
#include<stack>
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

void inorder(Node *root, stack<Node*>&s){
    while(root){
        s.push(root);
        root=root->left;
    }
}

// Return a integer of integers having all the nodes in both the BSTs in a sorted order.
vector<int> merge(Node *root1, Node *root2){
   
   stack<Node *> s1;
   stack<Node *> s2;
   
   inorder(root1, s1);
   inorder(root2, s2);
   
   vector<int>ans;
   
   while(!s1.empty() or !s2.empty()){
       int a=(!s1.empty() ? s1.top()->data:INT_MAX);
       int b=(!s2.empty() ? s2.top()->data:INT_MAX);
       
       if(a<=b){
            ans.push_back(a);
            Node *top = s1.top();
            s1.pop();
            inorder(top->right, s1);
       }
       else{
            ans.push_back(b);
            Node *top = s2.top();
            s2.pop();
            inorder(top->right, s2);
       }
   }
   
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