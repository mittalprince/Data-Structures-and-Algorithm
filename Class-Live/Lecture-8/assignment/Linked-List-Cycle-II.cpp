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

ListNode *detectCycle(ListNode *head) {
    if(head == NULL || head->next == NULL) return NULL;
    
    if(head->next == head){
        return head;
    }
    
    ListNode *fst=head, *slw=head;
    
    while(fst && fst->next){
        slw = slw->next;
        fst =fst->next->next;
        
        if(slw == fst){
            break;
        }
    }
    
    ListNode *ans=NULL;
    if(slw == fst){
        slw=head;
        
        while(slw != fst){
            slw = slw->next;
            fst = fst->next;
        }
        ans=slw;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}