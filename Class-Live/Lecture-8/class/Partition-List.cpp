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

ListNode* partition(ListNode* head, int x) {
    if(head==NULL || head->next == NULL) return head;
    
    ListNode *lth=NULL, *gth=NULL, *lt=NULL, *gt=NULL, *curr=head, *next=NULL;
    
    while(curr){
        next = curr->next;
        if(curr->val < x){
            if(lth==NULL){
                lth=curr;
                lt=curr;
            }
            else{
                lt->next = curr;
                lt = lt->next;
            }
        }
        else{
            if(gth==NULL){
                gth=curr;
                gt=curr;
            }
            else{
                gt->next = curr;
                gt = gt->next;
            }
        }
        curr->next = NULL;
        curr = next;
    }
    
    if(lth){
        lt->next=gth;
        return lth;
    }
    return gth;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}