//https://leetcode.com/problems/linked-list-in-binary-tree/
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

struct ListNode{
    *int val;
    *ListNode *next;
    *ListNode() : val(0), next(nullptr){} 
    *ListNode(int x) : val(x), next(nullptr){} 
    *ListNode(int x, ListNode *next) : val(x), next(next){}
                                                                                                                                      
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool findSubPath(ListNode* head, TreeNode* root) {
    if (!head) return true;
    if (!root) return false;
    return head->val == root->val && (findSubPath(head->next, root->left) || findSubPath(head->next, root->right));
}

bool isSubPath(ListNode* head, TreeNode* root) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!root) return false;
    return findSubPath(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
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