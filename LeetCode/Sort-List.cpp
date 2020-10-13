// https://leetcode.com/problems/sort-list/
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
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* merge(ListNode *h1, ListNode *h2){
    if(h1 == NULL)return h2;
    if(h2 == NULL) return h1;

    ListNode *head=NULL, *temp=NULL;

    while(h1 and h2){
        if(h1->val <= h2->val){
            if(head==NULL){
                head=h1;
                temp=h1;
            }
            else{
                temp->next = h1;
                temp=temp->next;
            }
            h1 = h1->next;
        }
        else{
            if(head==NULL){
                head=h2;
                temp=h2;
            }
            else{
                temp->next = h2;
                temp=temp->next;
            }
            h2 = h2->next;
        }
    }

    if(h1){
        temp->next=h1;
    }
    if(h2){
        temp->next = h2;
    }

    return head;
}

ListNode* sortList(ListNode *head){
    if(head==NULL or head->next==NULL)return head;

    ListNode *fst = head->next, *slw=head;

    while(fst and fst->next){
        fst = fst->next->next;
        slw = slw->next;
    }

    ListNode *fh = head, *sh = slw->next;
    slw->next=NULL;

    fh = sortList(fh);
    sh = sortList(sh);

    head = merge(fh, sh);
    return head;
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