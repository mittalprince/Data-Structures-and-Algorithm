// https://leetcode.com/problems/add-two-numbers/
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
 
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *res = new ListNode(-1);
    ListNode *prev = res;
    int carry=0, val=0;
    while(l1 && l2){
        val = l1->val + l2->val + carry;
        l1->val = val%10;
        carry = val/10;

        prev->next = l1;
        prev = l1;
        l1 = l1->next;
        l2 = l2->next;
    }
    prev->next = l1 ? l1 : l2;
    ListNode *t = prev->next;
    while(carry && t){
        val = t->val+carry;
        t->val = val%10;
        carry = val/10;
        prev = t;
        t = t->next;
    }
    if(carry){
        prev->next = new ListNode(carry);
    }
    return res->next;
}

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}