// https://leetcode.com/problems/partition-list/
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

ListNode* partition(ListNode* head, int x) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(head==NULL or head->next == NULL)return head;
    ListNode *lh=NULL, *lt=NULL, *gh=NULL, *gt=NULL;
    ListNode *next=NULL;

    while(head){
        next = head->next;
        if(head->val<x){
            if(lh==NULL){
                lh=head;
                lt=head;
            }
            else{
                lt->next=head;
                lt=lt->next;
            }
        }
        else{
            if(gh==NULL){
                gh=head;
                gt=head;
            }
            else{
                gt->next=head;
                gt=gt->next;
            }
        }
        head->next=NULL;
        head=next;
    }

    if(lh){
        lt->next=gh;
        return lh;
    }

    return gh;
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