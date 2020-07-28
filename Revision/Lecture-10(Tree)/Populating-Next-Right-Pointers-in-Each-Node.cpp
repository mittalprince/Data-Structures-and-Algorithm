// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
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

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* getNextRight(Node *root){
    Node *p = root->next;
    while(p){
        if(p->left)return p->left;
        if(p->right)return p->right;

        p = p->next;
    }
    return NULL;
}
Node* connect(Node* root) {
    if(!root)return root;

    Node *ans=root;
    while(root){
        Node *temp = root;
        while(temp){
            if(temp->left){
                if(temp->right)temp->left->next = temp->right;
                else{
                    temp->left->next = getNextRight(temp);
                }
            }
            if(temp->right){
                temp->right->next = getNextRight(temp);
            }
            temp = temp->next;
        }
        if(root->left) root=root->left;
        else if(root->right) root=root->right;
        else{
            root = getNextRight(root);
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