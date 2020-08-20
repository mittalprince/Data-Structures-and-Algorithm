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

void sortedInsert(ListNode* &head, int x){   
    ListNode *new_node = new ListNode(x);
    if(head == NULL){
        new_node->next = new_node;
        head = new_node;
        return;
    }
    
    if(head->val >= x){
        ListNode *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        new_node->next = head;
        temp->next = new_node;
        head = new_node;
        return;
    }
    
    ListNode *temp = head;
    while(temp->next && temp->next != head && temp->next->val < x){
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}