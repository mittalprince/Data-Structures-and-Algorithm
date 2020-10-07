// https://leetcode.com/problems/rotate-list/
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

class ListNode{
    public:
    int val;
    ListNode *next;

    ListNode():val(0),next(NULL){}
    ListNode(int val):val(val),next(NULL){}
};

int length(ListNode *head){
    int len=0;
    while(head){
        head=head->next;
        len++;
    }
    return len;
}

ListNode *reverse(ListNode *head){
    ListNode *curr=head, *prev=NULL, *next=NULL;
    while(curr){
        next = curr->next;
        curr->next=prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

ListNode *reverse(ListNode *&head, int k){
    ListNode *curr=head, *prev=NULL, *next=NULL;

    while(curr and k--){
        next = curr->next;
        curr->next=prev;
        prev = curr;
        curr = next;
    }

    head=prev;
    return curr;
}

ListNode* rotateRight(ListNode* head, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(head==NULL or head->next==NULL){
        return head;
    }
    int len = length(head);
    k %= len;
    if(k==0)return head;

    ListNode *new_head = reverse(head);

    ListNode *temp = new_head;

    ListNode *curr = reverse(new_head, k);
    ListNode *sh = reverse(curr);

    temp->next=sh;

    return new_head;

}

// Rotate one by one
ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL || head->next == NULL) return head;
    int i = 0;
    ListNode* curr = head;
    while(curr != NULL) {
        curr = curr-> next;
        i ++;
    }
    k = k%i;
    return rotato(head, k);
}

ListNode* rotato(ListNode* head, int k) {
    if(k <= 0) return head;
    ListNode* curr = head;
    while(curr->next->next != NULL) {
        curr = curr-> next;
    }
    ListNode* temp = curr->next;
    curr->next = NULL;
    temp->next = head;
    head = temp;

    return rotato(head, k-1);
}

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