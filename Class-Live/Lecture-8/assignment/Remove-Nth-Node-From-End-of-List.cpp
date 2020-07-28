#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode() : val(0), next(NULL) {}
    ListNode(int val) : val(val), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    ListNode *fst=head, *slw=head, *prev=NULL;
    while(n--){
        fst = fst->next;
    }

    while(fst){
        fst = fst->next;
        prev = slw;
        slw = slw->next;
    }

    ListNode *temp = slw;
    if(prev){
        prev->next = slw->next;   
    }
    else{
        head = head->next;
    }
    delete temp;
    return head;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}