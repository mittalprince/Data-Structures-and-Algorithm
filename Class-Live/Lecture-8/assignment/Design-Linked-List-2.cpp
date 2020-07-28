#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    class ListNode{
        public:
        int val;
        ListNode *next;
        
        ListNode(int val):val(val),next(NULL){}
    };
    
    ListNode *prev, *tail;
    int size;
    
    MyLinkedList() {
        ListNode *t = new ListNode (-1);
        prev=t;
        tail=t;
        size=0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >=size) return -1;
        ListNode *p=prev->next;
        while(index){
            p = p->next;
            index--;
        }
        return p->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode *new_head = new ListNode(val);
        ListNode *old_head = prev->next;
        prev->next=new_head;
        new_head->next = old_head;
        size++;
        
        if(size == 1) tail=new_head;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *new_tail = new ListNode(val);
        tail->next = new_tail;
        tail = new_tail;
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > size) return;
        
        if(index == 0){
            addAtHead(val);
            return;
        }
        if(index == size){
            addAtTail(val);
            return;
        }
        ListNode *new_node = new ListNode(val);
        ListNode *t = prev;
        while(index){
            t=t->next;
            index--;
        }
        new_node->next = t->next;
        t->next = new_node;
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= size) return;
        
        ListNode *t=prev;
        for(int i=0; i<index; i++){
            t=t->next;
        }
        if(index == (size-1)) tail=t;
        ListNode *del = t->next;
        t->next = del->next;
        delete del;
        size--;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}