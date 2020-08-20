// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(head == NULL || head->next == NULL) return NULL;

    ListNode *start=new ListNode(0);
    start->next=head;
    ListNode *fst=head, *slw=head, *prev=start;

    while(n-- && fst){
        fst = fst->next;
    }

    while(fst){
        fst = fst->next;
        prev = slw;
        slw = slw->next;
    }
    prev->next = slw->next;
    delete slw;
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