// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
void solve(TreeNode *root, vector<int>&arr){
    if(root==NULL)return;
    solve(root->left, arr);
    arr.push_back(root->val);
    solve(root->right, arr);
}

vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int>a,b;
    solve(root1, a);
    solve(root2, b);
    int n=a.size(), m=b.size();
    
    if(!n)return b;
    if(!m)return a;
    
    vector<int>ans;
    int i=0, j=0;
    
    while(i<n and j<m){
        if(a[i]<=b[j]){
            ans.push_back(a[i++]);
        }
        else ans.push_back(b[j++]);
    }
    
    while(i<n){
        ans.push_back(a[i++]);
    }
    while(j<m){
        ans.push_back(b[j++]);
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