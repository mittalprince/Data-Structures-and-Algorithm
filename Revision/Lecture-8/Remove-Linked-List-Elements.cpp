// https://leetcode.com/problems/remove-linked-list-elements/
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

    ListNode(int v):val(v),next(NULL){}
};

ListNode* removeElements(ListNode* head, int val) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(head==NULL)return head;
    if(head->next==NULL and head->val == val)return NULL;

    ListNode *start = new ListNode(0);
    start->next=head;

    ListNode *curr = head;
    ListNode *prev = start;

    while(curr){
        if(curr->val == val){
            prev->next = curr->next;
        }
        else prev=curr;
        curr = curr->next;
    }

    return start->next;
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