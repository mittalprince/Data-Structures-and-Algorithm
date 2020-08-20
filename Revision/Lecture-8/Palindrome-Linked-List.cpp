// https://leetcode.com/problems/palindrome-linked-list/
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

class ListNode{
    public:
    int val;
    ListNode *next;

    ListNode(int v):val(v),next(NULL){}
};

void reverse(ListNode *&head){
    ListNode *curr=head, *prev=NULL, *next=NULL;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

ListNode *middle(ListNode *head){
    if(head == NULL) return head;

    ListNode *fst=head->next, *slw=head;

    while(fst && fst->next){
        fst = fst->next->next;
        slw = slw->next;
    }
    return slw;
}
bool isPalindrome(ListNode* head) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(head==NULL or head->next==NULL)return true;

    ListNode *mid = middle(head);
    ListNode *h1=head, *h2=mid->next;
    reverse(h2);
    mid->next = NULL;

    while(h1 and h2){
        if(h1->val != h2->val)return false;
        h1 = h1->next;
        h2 = h2->next;
    }
    return true;
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