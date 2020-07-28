// https://hack.codingblocks.com/app/practice/2/1069/problem
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;

    node(int d) : data(d), left(NULL), right(NULL) {}
};

node* insert(node *root, int key){
    if(root == NULL){
        node *temp = new node(key);
        return temp;
    }

    if(key <= root->data){
        root->left = insert(root->left, key);
    }
    else{
        root->right = insert(root->right, key);
    }
    return root;
}

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
