#include<iostream>
#include<vector>
#include<queue>
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

class compare{
    public:

    bool operator()(ListNode* a, ListNode* b){
        return a->val>b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, compare>pq;

    for(ListNode* &i: lists){
        if(i){
            pq.push(i);
            i=i->next;   
        }
    }

    ListNode *head=NULL, *temp;

    while(!pq.empty()){
        ListNode* top = pq.top();
        pq.pop();
        if(head == NULL){
            head = top;
            temp = top;
        }
        else{
            temp->next=top;
            temp = temp->next;
        }

        if(top->next){
            top = top->next;
            pq.push(top);
        }
    }
    return head;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}