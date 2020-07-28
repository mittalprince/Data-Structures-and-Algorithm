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

ListNode* removeElements(ListNode* head, int val) {
    if(head == NULL) return head;
    if(head->val == val && head->next == NULL) return NULL;
    
    ListNode *start=new ListNode(0);
    start->next=head;
    ListNode *curr=start->next;
    ListNode *prev=start;
    

    while(curr){
        if(curr->val == val){
            prev->next = curr->next;
        }
        else prev = curr;
        curr = curr->next;
    }
    return start->next;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}