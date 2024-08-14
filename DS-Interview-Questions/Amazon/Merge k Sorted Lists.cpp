// https://leetcode.com/problems/merge-k-sorted-lists/
#include<iostream>
#include<vector>
#include<queue>
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

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){} 
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}                                                                                                                           *
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    auto cmp = [](const ListNode* a, const ListNode *b){
        return a->val>b->val;
    };

    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)>pq(cmp);

    for(ListNode* &i: lists){
        if(i){
            pq.push(i);
            i = i->next;
        }
    }

    ListNode *head=NULL, *temp;

    while(!pq.empty()){
        ListNode *top=pq.top();
        pq.pop();

        if(head==NULL){
            head=top;
            temp=top;
        }
        else{
            temp->next=top;
            temp = temp->next;
        }

        if(top->next){
            top = top->next;
            pq.push(top);
        }
    }
    return head;
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