// https://www.hackerrank.com/challenges/tree-top-view/problem
#include<iostream>
#include<vector>
#include<map>
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

void helper(Node* root,int hd, int level, map<int, pair<int, int>>&mp){
    if(root==NULL) return;
    if(mp.find(hd) == mp.end() || level<mp[hd].second) mp[hd]= {root->data, level};
    if(root->left) helper(root->left, hd-1, level+1, mp);
    if(root->right)helper(root->right, hd+1, level+1, mp);
}
void topView(Node * root) {
    if(root==NULL) return;
    map<int, pair<int, int>>mp;
    helper(root,0, 0, mp);
    for(auto i:mp) cout<<i.second.first<<" ";;
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