// https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1
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

void serialize(Node *root,vector<int> &A){
    if(root==NULL){
        A.push_back(-1);
        return;
    }
    A.push_back(root->data);
    serialize(root->left, A);
    serialize(root->right, A);
}

/*this function deserializes
 the serialized vector A*/
 int i=0;
Node * deSerialize(vector<int> &A){
   if(A[i] == -1 || i==A.size()){
       i++;
       i %= A.size();
       return NULL;
   }
   Node *root = new Node(A[i]);
   i++;
   root->left = deSerialize(A);
   root->right = deSerialize(A);
   
   return root;
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