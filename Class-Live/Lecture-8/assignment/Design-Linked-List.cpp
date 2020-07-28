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
    
    ListNode *head, *tail;
    int size;
    
    void print(ListNode*head){
        while(head){
            cout<<head->val<<" ";
            head=head->next;
        }
        cout<<endl;
    }
    
    MyLinkedList() {
        head = tail = NULL;
        size=0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= size) return -1;
        
        int ct=0;
        ListNode *t=head;
        while(ct<index){
            t = t->next;
            ct++;
        }
        return t->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode *temp = new ListNode(val);
        temp->next = head;
        head = temp;
        // if(tail == NULL) tail = head;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(head == NULL){
            addAtHead(val);
            return;
        }
        // print(head);
        ListNode *temp=head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = new ListNode(val);
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > size) return;
        
        if(index == 0){
            addAtHead(val);
            return;
        }
        
        int ct=1;
        ListNode *t=head;
        while(ct<index){
            t = t->next;
            ct++;
        }
        ListNode *n = new ListNode(val);
        n->next = t->next;
        t->next = n;
        size++;
        // print(head);
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= size) return;
        
        if(index == 0){
            ListNode *t=head;
            head = head->next;
            delete t;
        }
        else{
            int ct=1;
            ListNode *t=head;
            while(ct<index){
                t = t->next;
                ct++;
            }
            ListNode *del = t->next;
            t->next = del->next;
            delete del;
        }
        size--;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}