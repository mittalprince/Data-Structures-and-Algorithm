// https://leetcode.com/problems/odd-even-linked-list/
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
};

ListNode* oddEvenList(ListNode* head) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(head==NULL or head->next==NULL or head->next->next==NULL)return head;

    ListNode *oh=head, *odd=head;
    ListNode *eh=head->next, *even=head->next;
    ListNode *prev=head->next;
    int cnt=3;

    head=head->next->next;

    while(head){
        if(prev){
            prev->next=NULL;
        }
        if(cnt&1){
            odd->next = head;
            odd=odd->next;
        }
        else{
            even->next = head;
            even = even->next;
        }
        cnt++;
        prev=head;
        head=head->next;
    }

    odd->next=eh;
    return oh;
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