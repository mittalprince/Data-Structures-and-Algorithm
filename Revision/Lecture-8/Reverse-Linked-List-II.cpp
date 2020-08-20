// https://leetcode.com/problems/reverse-linked-list-ii/
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

ListNode* reverseBetween(ListNode* head, int m, int n) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(head==NULL or head->next==NULL)return head;

    ListNode *start = new ListNode(0);
    start->next = head;

    int b=m;
    ListNode *prev_of_start=NULL, *curr=start;
    while(m--){
        prev_of_start=curr;
        curr = curr->next;
    }

    ListNode *prev=NULL, *next=NULL, *holder=curr;
    int len = n-b+1;

    while(curr and len--){
        next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    if(prev_of_start){
        prev_of_start->next = prev;
    }
    holder->next = curr;

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