//
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

int length(ListNode *head){
    int len=0;
    while(head){
        len++;
        head = head->next;
    }
    return len;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(headA == NULL || headB == NULL){
        return NULL;
    }  

    int lenA = length(headA);
    int lenB = length(headB);

    if(lenA>lenB){
        while(lenA!=lenB){
            headA = headA->next;
            lenA--;
        }
    }
    else{
        while(lenA!=lenB){
            headB = headB->next;
            lenB--;
        }
    }

    while(headA != headB){
        headA=headA->next;
        headB=headB->next;
    }
    return headA;
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