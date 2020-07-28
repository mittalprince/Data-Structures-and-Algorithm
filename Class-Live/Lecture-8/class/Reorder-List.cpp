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
};

ListNode* middle(ListNode *head){
    if(head==NULL || head->next == NULL) return head;
    ListNode *slw = head, *fst=head->next;

    while(fst && fst->next){
        fst = fst->next->next;
        slw = slw->next;
    }
    return slw;
}

void Reverse(ListNode* &head){
    ListNode *prev=NULL, *curr=head, *next=head;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } 

    head = prev;
}

void reorderList(ListNode* head) {
    if(head==NULL || head->next == NULL) return;

    ListNode *mid = middle(head);
    ListNode *h1=head, *h2=mid->next;
    mid->next = NULL;
    Reverse(h2);
    ListNode *x, *y;

    while(h1 && h2){
        x = h1->next;
        y = h2->next;

        h1->next = h2;
        h1 = x;

        h2->next = h1;
        h2 = y;
    }
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}