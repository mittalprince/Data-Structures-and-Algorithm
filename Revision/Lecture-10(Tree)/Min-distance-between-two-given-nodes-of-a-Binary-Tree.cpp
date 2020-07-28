// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1/
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

Node *LCA(Node *root, int a, int b, int &d1, int &d2, int &dist, int level){
    if(root==NULL)return root;

    if(root->data == a){
        d1=level;
        return root;
    }

    if(root->data == b){
        d2=level;
        return root;
    }

    Node *left = LCA(root->left, a, b, d1, d2, dist, level+1);
    Node *right = LCA(root->right, a, b, d1, d2, dist, level + 1);

    if(left and right){
        dist = (d1+d2) - 2*level;
        return root;
    }

    return left?left:right;
}

int findLevel(Node *root, int level, int a){
    if(root==NULL)return -1;
    if(root->data == a){
        return level;
    }

    int left = findLevel(root->left, level+1, a);
    if(left != -1) return left;

    return findLevel(root->right, level+1, a);
}

int findDist(Node* root, int a, int b) {
    if(root==NULL)return 0;

    int d1=-1, d2=-1, dist=0;
    Node *lca = LCA(root, a, b, d1, d2, dist, 1);

    if(d1 != -1 and d2 != -1){
        return dist;
    }

    if(d1 != -1){
        return findLevel(lca, 0, a);
    }

    if(d2 != -1){
        return findLevel(lca, 0, b);
    }

    return -1;
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