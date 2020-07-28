// https://practice.geeksforgeeks.org/problems/node-at-distance/1/
#include<iostream>
#include<vector>
#include<unordered_set>
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

unordered_set<Node*>s;

void countNodes(Node *root, int k, vector<Node*>v){
    if(!root)return;
    v.push_back(root);

    if(!root->left and !root->right and v.size()>k){
        s.insert(v[v.size()-k-1]);
        return;
    }
    countNodes(root->left, k, v);
    countNodes(root->right, k, v);
}

int printKDistantfromLeaf(Node *root, int k){
    if(root==NULL)return 0;
    s.clear();
    vector<Node*>v;
    countNodes(root, k, v);
    return s.size();
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