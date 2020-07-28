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

bool hasCycle(ListNode *head) {
    if(head == NULL || head->next == NULL)
        return false;
    
    ListNode *slow = head, *fast = head;
    
    while(slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast)
            return true;
    }
    
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}