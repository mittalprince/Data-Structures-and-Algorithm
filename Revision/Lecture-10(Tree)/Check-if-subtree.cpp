// https://practice.geeksforgeeks.org/problems/check-if-subtree/1/
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

bool chk(Node* s, Node* t){
    if (s==NULL && t==NULL) return true;
    if (s==NULL || t==NULL) return false;
    if (s->data!= t->data) return false;
    return chk(s->left, t->left) && chk(s->right, t->right);
}
bool isSubTree(Node* s, Node* t) {
    if (s==NULL && t==NULL) return true;
    if (s==NULL || t==NULL) return false;
    return chk(s, t) || isSubTree(s->left, t) || isSubTree(s->right, t);
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