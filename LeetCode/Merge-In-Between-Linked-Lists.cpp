//https://leetcode.com/problems/merge-in-between-linked-lists/
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

ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ListNode *p=list1;
    for(int i=0; i<a-1; i++){
        p=p->next;
    }
    ListNode *q=list1;
    for(int i=0; i<=b; i++){
        q=q->next;
    }
    ListNode *x=list2;
    while(x->next)x=x->next;

    p->next=list2;
    x->next=q;

    return list1;
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