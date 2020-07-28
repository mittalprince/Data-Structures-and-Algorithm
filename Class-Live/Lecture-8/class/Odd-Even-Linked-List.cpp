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

// my ways
ListNode* oddEvenList1(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    ListNode *odd=NULL, *even=NULL, *temp1, *temp2, *curr=head, *next;
    
    while(curr && curr->next){
        next = curr->next->next;
        
        if(odd==NULL){
            odd=curr;
            even=curr->next;
            even->next=NULL;
            temp1=odd;
            temp2=even;
        }
        else{
            temp1->next = curr;
            temp2->next = curr->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
            temp2->next = NULL;
        }
        curr=next;
        if(curr && !curr->next){
            temp1->next = curr;
            temp1=temp1->next;
            break;
        }
    }
    
    temp1->next = even;
    return odd;
}

ListNode* oddEvenList(ListNode *head){
    if(head == NULL || head->next == NULL) return head;

    ListNode *oddh=NULL, *evenh=NULL, *prev=NULL, *curr=head, *next=NULL;
    oddh = head;
    evenh = head->next;
    int jumps = 0;
    while(curr && curr->next){
        next = curr->next;
        curr->next = next->next;
        prev = curr;
        curr=next;
        jumps++;
    }

    // when we have even jumps (i.e odd elemets) then curr will be al least node, so joind it with evenh
    if(jumps%2==0){
        curr->next=evenh;
    }
    else{
        // when we have odd jumps
        // we have even elemtns then in case our curr will be pointing at null
        // so we use prev
        prev->next = evenh;
    }
    return oddh;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}