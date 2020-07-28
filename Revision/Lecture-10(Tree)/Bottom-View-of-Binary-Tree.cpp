// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1/?track=PC-W6-BST&batchId=154
#include<iostream>
#include<vector>
#include<map>
#include<queue>
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

void helper(Node*root, int hd, int h, map<int,pair<int,int>>&mp){
    if(root==NULL) return;
    
    if(mp.find(hd) == mp.end() || h>mp[hd].second){
        mp[hd]={root->data, h};
    }
    helper(root->left,hd-1,h+1,mp);
    helper(root->right,hd+1,h+1,mp);
    
}
void bottomView(Node *root)
{
   if(root==NULL) return;
   queue<pair<Node*, int> >q;
   q.push({root, 0});
   
   map<int, int>m;
   
   while(!q.empty()){
       pair <Node*, int>top = q.front();
       q.pop();
       
       m[top.second] = top.first->data;
       if(top.first->left){
           q.push({top.first->left, top.second-1});
       }
       if(top.first->right){
           q.push({top.first->right, top.second+1});
       }
   }
   
   for(auto it: m){
       cout<<it.second<<" ";
   }
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