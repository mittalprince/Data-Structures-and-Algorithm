// https://leetcode.com/problems/design-linked-list/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

class MyLinkedList {
public:
    
    class ListNode{
        public:
        int val;
        ListNode *next;
        
        ListNode(int v):val(v), next(NULL){}
    };
    
    ListNode *prev, *tail;
    int size;
    
    MyLinkedList() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        ListNode *t = new ListNode(-1);
        tail=prev=t;
        size=0;
    }
    
    int get(int index) {
        if(index<size){
            ListNode *p = prev->next;
            while(index--){
                p = p->next;
            }
            return p->val;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        ListNode *new_head = new ListNode(val);
        ListNode *old_head = prev->next;
        prev->next = new_head;
        new_head->next = old_head;
        
        size++;
        if(size==1)tail=new_head;
    }
    
    void addAtTail(int val) {
        ListNode *new_tail = new ListNode(val);
        tail->next = new_tail;
        tail = new_tail;
            
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>size)return;
        
        if(index==0){
            addAtHead(val);
            return;
        }
        if(index == size){
            addAtTail(val);
            return;
        }
        
        ListNode *p=prev;
        while(index--){
            p=p->next;
        }
        ListNode *new_node = new ListNode(val);
        new_node->next = p->next;
        p->next = new_node;
        
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index>=size)return;
        
        ListNode *p=prev;
        for(int i=0; i<index; i++){
            p = p->next;
        }
        
        if(index == (size-1))tail=p;
        ListNode *del = p->next;
        p->next = del->next;
        
        delete del;
        size--;
    }
};


int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}