// https://leetcode.com/problems/linked-list-cycle/
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

    ListNode(int v):val(v),next(NULL){}
};

bool hasCycle(ListNode *head) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ListNode *fst=head, *slw=head;

    while(fst and fst->next){
        fst = fst->next->next;
        slw = slw->next;

        if(slw == fst)return true;
    }

    return false;
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