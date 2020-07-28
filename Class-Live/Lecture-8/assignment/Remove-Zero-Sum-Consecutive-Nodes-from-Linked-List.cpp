#include<iostream>
#include<vector>
#include<map>
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

ListNode* removeZeroSumSublists(ListNode* head) {
    if(head==NULL) return head;

    ListNode *start = new ListNode(0);
    start->next = head;
    ListNode *prev=start, *curr;
    int sum=0;

    while(prev){
        sum = 0;
        curr = prev->next;
        while(curr){
            sum += curr->val;
            if(sum==0){
                prev->next = curr->next;
            }
            curr = curr->next;
        }
        prev = prev->next;
    }
    return start->next;
}

ListNode* removeZeroSumSublistsR(ListNode* head) {
    map<int, ListNode*>m;
    m[0] = NULL;
    ListNode *curr=head;
    int sum=0;
    while(curr){
        sum += curr->val;
        if(m.find(sum) == m.end()){
            m[sum] = curr;
        }
        else{
            ListNode *t = m[sum];
            if(t){
                t->next = curr->next;
                return removeZeroSumSublists(head);
            }
            else return removeZeroSumSublists(curr->next);
        }
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