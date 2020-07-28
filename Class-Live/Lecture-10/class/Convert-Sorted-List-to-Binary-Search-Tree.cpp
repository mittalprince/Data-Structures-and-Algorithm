#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class TreeNode{
    public:
    int val;
    TreeNode *left, *right;

    TreeNode():val(0),left(NULL),right(NULL){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class ListNode{
    public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* middle(ListNode *head){
    if(head == NULL) return head;
    ListNode *fst=head, *slw=head, *prev=NULL;

    while(fst && fst->next){
        fst=fst->next->next;
        prev=slw;
        slw=slw->next;
    }
    if(prev){
        prev->next=NULL;
    }
    return slw;
}

TreeNode *convert(ListNode *head){
    if(head==NULL) return NULL;

    ListNode *mid=middle(head);
    TreeNode *root=new TreeNode(mid->val);

    if(head==mid) return root;

    root->left = convert(head);
    root->right = convert(mid->next);
    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    return convert(head);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}