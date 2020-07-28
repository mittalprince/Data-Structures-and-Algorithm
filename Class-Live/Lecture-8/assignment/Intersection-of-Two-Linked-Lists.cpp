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

 int length(ListNode* head){
    int ans=0;
    while(head){
        head = head->next;
        ans++;
    }
    return ans;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == NULL || headB == NULL){
        return NULL;
    }  
    int lenA = length(headA);
    int lenB = length(headB);
    
    if(lenA>lenB){
        while(lenA != lenB){
            headA = headA->next;
            lenA--;
        }
    }
    else{
        while(lenA != lenB){
            headB = headB->next;
            lenB--;
        }
    }
    
    while(headA && headB){
        if(headA == headB){
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}