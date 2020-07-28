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

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if(head == NULL || head->next == NULL) return head;
    
    ListNode *start = new ListNode(0);
    start->next = head;
    
    int b=m;
    
    ListNode *prev_of_start=NULL, *curr=start;
    while(m--){
        prev_of_start=curr;
        curr=curr->next;
    }
    
    ListNode *prev=NULL, *next=NULL, *holder=curr;
    int len = n-b+1;
    
    while(curr && len--){
        next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    if(prev_of_start){
        prev_of_start->next = prev;
    }
    holder->next = curr;
    
    return start->next;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}