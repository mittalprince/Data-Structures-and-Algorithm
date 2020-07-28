// https://leetcode.com/problems/maximum-width-of-binary-tree/
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

class TreeNode{
    public:
    int val;
    TreeNode *left, *right;

    TreeNode():val(0),left(NULL),right(NULL){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int widthOfBinaryTree(TreeNode* root) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(root==NULL)return 0;
    queue<pair<TreeNode*, unsigned long long int> >q;
    q.push({root, 1});
    unsigned long long int ans=0;

    while(!q.empty()){
        int sz = q.size();
        unsigned long long int left = q.front().second, right=0;

        for(int i=0; i<sz; i++){
            auto top = q.front();
            q.pop();
            right = top.second;

            if(top.first->left){
                q.push({top.first->left, 2*right});
            }
            if(top.first->right){
                q.push({top.first->right, 2*right+1});
            }
        }
        ans = max(ans, right-left+1);
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