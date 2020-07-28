#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class node{
public:
    int data;
    node *left, *right;

    node(int d) : data(d), left(NULL), right(NULL) {}
};

void traversal(node *root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    traversal(root->left);
    traversal(root->right);
}

node* buildTree(int arr[], int s, int e){
    if(s > e){
        return NULL;
    }

    int mid = (s+e)>>1;
    node *root = new node(arr[mid]);
    root->left = buildTree(arr, s, mid-1);
    root->right = buildTree(arr, mid+1, e);

    return root;
}

void fromArr(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        node *root = buildTree(arr, 0, n - 1);
        traversal(root);
        cout << endl;
    }
}
int main(){
    fromArr();
}
