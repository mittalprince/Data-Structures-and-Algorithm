#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
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
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}