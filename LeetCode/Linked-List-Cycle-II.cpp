//https://leetcode.com/problems/linked-list-cycle-ii/
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

ListNode *detectCycle(ListNode *head) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(head==NULL or head->next==NULL)return NULL;

    if(head->next==head)return head;

    ListNode *fst=head, *slw=head;

    while(fst and fst->next){
        fst = fst->next->next;
        slw = slw->next;

        if(fst == slw){
            break;
        }
    }

    ListNode *ans=NULL;
    if(slw == fst){
        slw=head;
        while(slw != fst){
            fst=fst->next;
            slw=slw->next;
        }
        ans = slw;
    }
    return ans;
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