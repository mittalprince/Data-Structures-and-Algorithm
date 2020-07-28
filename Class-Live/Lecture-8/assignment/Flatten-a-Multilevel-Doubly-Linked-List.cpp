#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

// iterative
Node* flat(Node *head){
    Node *curr=head;
    while(curr){
        if(curr->child){
            Node *next = curr->next;
            curr->next = curr->child;
            curr->next->prev = curr;
            curr->child = NULL;
            Node *tail = curr->next;
            while(tail->next){
                tail = tail->next;
            }
            tail->next = next;
            if(next) next->prev = tail;
        }
        curr =curr->next;
    }
    return head;
}

// recurrsive
Node* convert(Node *head){
    Node *curr=head, *prev=NULL;

    while(curr){
        if(curr->child){
            Node* tail = convert(curr->child);
            Node *next = curr->next;
            curr->next = curr->child;
            curr->next->prev = curr;
            curr->child=NULL;
            tail->next = next;
            if(next){
                next->prev = tail;
            }
        }
        prev=curr;
        curr = curr->next;
    }
    return prev;
}

Node* flatten(Node* head) {
    if(head == NULL) return head;
    Node* temp = convert(head);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}