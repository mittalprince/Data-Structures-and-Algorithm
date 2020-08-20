// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
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

Node* flatten(Node* head) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *curr=head;
    while(curr){
        if(curr->child){
            Node *next = curr->next;
            curr->next = curr->child;
            curr->next->prev = curr;
            curr->child=NULL;

            Node *tail = curr->next;
            while(tail->next){
                tail = tail->next;
            }
            tail->next = next;
            if(next) next->prev= tail;
        }
        curr = curr->next;
    }

    return head;
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