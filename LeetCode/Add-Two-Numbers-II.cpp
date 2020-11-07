//https://leetcode.com/problems/add-two-numbers-ii/
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

ListNode *reverse(ListNode *head){
    ListNode *curr=head, *prev=NULL, *next;

    while(curr){
        next = curr->next;
        curr->next=prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(l1==NULL)return l2;
    if(l2==NULL)return l1;

    l1 = reverse(l1);
    l2 = reverse(l2);

    ListNode *t1=l1, *t2=l2, *prev=NULL;
    int carry=0;

    while(l1 and l2){
        int val = l1->val+l2->val+carry;
        l1->val = val%10;
        carry = val/10;
        prev = l1;
        l1 = l1->next;
        l2 = l2->next;
    }

    if(carry and !l1 and !l2){
        prev->next = new ListNode(carry);
        l1 = reverse(t1);
        return l1;
    }

    prev->next = l1?l1:l2;

    while(l1){
        int val = l1->val+carry;
        l1->val = val%10;
        carry = val/10;
        prev = l1;
        l1 = l1->next;
    }
    while(l2){
        int val = l2->val+carry;
        l2->val = val%10;
        carry = val/10;
        prev = l2;
        l2 = l2->next;
    }

    if(carry){
        prev->next = new ListNode(carry);
    }
    l1 = reverse(t1);
    return l1;
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