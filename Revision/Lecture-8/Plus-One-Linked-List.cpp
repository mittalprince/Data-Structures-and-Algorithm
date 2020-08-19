// https://baihuqian.github.io/2018-08-16-plus-one-linked-list/
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

    ListNode(int val):val(val),next(NULL){}
};

int findCarry(ListNode *head){
    if(head==NULL)return 1;
    
    int val = head->val + findCarry(head->next);
    head->val = val%10;
    return val%10;
}

ListNode* plusOne(ListNode *head){
    if(head==NULL)return head;

    int carry = findCarry(head);
    if(carry){
        ListNode *start = new ListNode(1);
        start->next=head;
        head=start;
    }
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