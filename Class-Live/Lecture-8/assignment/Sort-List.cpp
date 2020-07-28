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

ListNode* merge(ListNode *h1, ListNode *h2){
    if(h1 == NULL || h2 == NULL) return h1?h1:h2;

    ListNode *head=NULL, *temp=NULL;

    while(h1 && h2){
        if(h1->val <= h2->val){
            if(head==NULL){
                head = h1;
                temp=h1;
            }
            else{
                temp->next = h1;
                temp = temp->next;
            }
            h1 = h1->next;
        }
        else{
            if(head==NULL){
                head = h2;
                temp=h2;
            }
            else{
                temp->next = h2;
                temp = temp->next;
            }
            h2 = h2->next;
        }
    }

    if(h1){
        temp->next = h1;
    }
    if(h2){
        temp->next = h2;
    }
    return head;
}

ListNode* sortList(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;

    ListNode *fst=head->next, *slw=head;
    while(fst && fst->next){
        fst = fst->next->next;
        slw = slw->next;
    }

    ListNode *fh=head, *sh=slw->next;
    slw->next=NULL;

    fh = sortList(fh);
    sh = sortList(sh);

    head = merge(fh, sh);
    return head;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}