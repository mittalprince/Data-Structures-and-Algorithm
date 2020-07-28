#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class Node{
    public:
    int val;
    Node *left, *right, *next;

    Node():val(0),left(NULL),right(NULL),next(NULL){}
};

// using Level Order traversal
Node* connect(Node* root) {
    if(root==NULL) return root;
    queue<Node*>q;

    q.push(root);
    q.push(NULL);

    Node* prev=NULL;
    while(!q.empty()){
        Node* top = q.front();
        q.pop();

        if(top){
            if(prev){
                prev->next=top;
            }
            prev = top;
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
        }
        else{
            if(!q.empty()){
                q.push(NULL);
                prev=NULL;
            }
        }
    }

    return root;
}

class Solution {
public:
    Node* getNextRight(Node* p){
        Node *n = p->next;
        while(n){
            if(n->left){
                return n->left;
            }
            if(n->right){
                return n->right;
            }
            n=n->next;
        }
        return n;
    }
    Node* connect(Node* root) {
        if(root==NULL) return root;
        
        Node *ans=root;
        
        while(root){
            Node *temp=root;
            while(temp){
                if(temp->left){
                    if(temp->right) temp->left->next = temp->right;
                    else temp->left->next = getNextRight(temp);
                }
                if(temp->right) temp->right->next = getNextRight(temp);
                
                temp=temp->next;
            }
            
            if(root->left) root=root->left;
            else if(root->right) root=root->right;
            else{
                root = getNextRight(root);
            } 
        }
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}