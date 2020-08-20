// https://leetcode.com/problems/insertion-sort-list/
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

ListNode* insert(ListNode *head, ListNode *new_node){
    if(head == NULL || head->val > new_node->val){
        new_node->next = head;
        return new_node;
    }    
    ListNode *temp=head;
    while(temp->next && temp->next->val < new_node->val){
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

ListNode* insertionSortList(ListNode* head) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(head == NULL || head->next == NULL) return head;

    ListNode *curr=head, *sorted=NULL;
    while(curr){
        ListNode *next = curr->next;
        sorted = insert(sorted, curr);
        curr = next;
    }
    return sorted;
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