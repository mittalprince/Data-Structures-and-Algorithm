// https://leetcode.com/problems/next-greater-node-in-linked-list/
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
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

void reverse(ListNode *&head){
    ListNode *curr=head, *next=NULL, *prev=NULL;

    while(curr){
        next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}

vector<int> nextLargerNodes(ListNode* head) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(head==NULL)return {};
    vector<int>ans;

    reverse(head);
    stack<int>s;

    while(head){
        while(!s.empty() and s.top()<= head->val)s.pop();

        if(s.empty())ans.push_back(0);
        else ans.push_back(s.top());

        s.push(head->val);
        head = head->next;
    }

    std::reverse(ans.begin(), ans.end());
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