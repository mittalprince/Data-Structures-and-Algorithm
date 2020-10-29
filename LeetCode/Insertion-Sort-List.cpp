//https://leetcode.com/problems/insertion-sort-list/
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

ListNode *insertionSort(ListNode *sorted_head, ListNode *new_node){
    if(sorted_head==NULL or sorted_head->val > new_node->val){
        new_node->next=sorted_head;
        return new_node;
    }

    ListNode *temp = sorted_head;
    while(temp->next and temp->next->val<new_node->val){
        temp = temp->next;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    return sorted_head;
}

ListNode* insertionSortList(ListNode *head){
    if(head==NULL or head->next ==NULL)return head;

    ListNode *sorted_head=NULL;
    ListNode *curr=head;
    while(curr){
        ListNode *next = curr->next;
        sorted_head = insertionSort(sorted_head, curr);
        curr = next;
    }

    return sorted_head;
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