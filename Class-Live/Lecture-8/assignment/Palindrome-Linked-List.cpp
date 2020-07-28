#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class ListNode{
    public:
    int val;
    ListNode *next;

    ListNode():val(0),next(NULL){}
    ListNode(int val):val(val),next(NULL){}
};

ListNode *middle(ListNode *head){
    if(head == NULL) return NULL;

    ListNode *fst=head->next, *slw=head;

    while(fst && fst->next){
        fst = fst->next->next;
        slw = slw->next;
    }
    return slw;
}

ListNode* reverse(ListNode *head){
    ListNode *prev=NULL, *curr=head, *next;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr=next;
    }
    return prev;
}

bool isPalindrome(ListNode* head) {
    if(head == NULL || head->next==NULL){
        return true;
    }

    ListNode *mid = middle(head);
    ListNode *h2 = reverse(mid->next);
    mid->next=NULL;
    ListNode *h1=head;

    while(h1 && h2){
        if(h1->val != h2->val) return false;
        h1 = h1->next;
        h2 = h2->next;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}