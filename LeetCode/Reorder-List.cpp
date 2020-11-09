//https://leetcode.com/problems/reorder-list/
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *middle(ListNode *head){
    if(head==NULL or head->next==NULL)return head;

    ListNode *fst=head->next, *slw=head;

    while(fst and fst->next){
        fst=fst->next->next;
        slw=slw->next;
    }
    return slw;
}

void reverse(ListNode *&head){
    ListNode *curr=head, *next=NULL, *prev=NULL;

    while(curr){
        next = curr->next;
        curr->next=prev;
        prev = curr;
        curr = next;
    }
    head= prev;
}
void reorderList(ListNode* head) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(head==NULL or head->next==NULL)return;

    ListNode *mid = middle(head);

    ListNode *h1=head, *h2=mid->next;
    mid->next=NULL;

    reverse(h2);
    ListNode *x, *y;

    while(h1 && h2){
        x = h1->next;
        y = h2->next;

        h1->next=h2;
        h1 = x;

        h2->next=x;
        h2 = y;
    }
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