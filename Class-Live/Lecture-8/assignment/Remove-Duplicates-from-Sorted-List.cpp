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

ListNode* deleteDuplicates(ListNode* head) {
   if(head == NULL || head->next == NULL) return head;

    ListNode *curr=head, *temp;

    while(curr){
        temp = curr;
        while(temp->next && temp->val == temp->next->val){
            temp = temp->next;
        }
        curr->next = temp->next;
        curr = curr->next;
    }
    return head;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}