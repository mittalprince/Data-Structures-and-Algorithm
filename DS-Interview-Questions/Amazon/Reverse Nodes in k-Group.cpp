// https://leetcode.com/problems/reverse-nodes-in-k-group/
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

void reverse(ListNode* curr, ListNode* prev, int k){
    int ct=1;
    ListNode *next = curr->next;
    while(ct <= k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        ct++;
    }
}

ListNode* reverseKGroup(ListNode* head, int k) {
    int ct=0;
    ListNode *start = head;
    ListNode *prev = NULL;
    ListNode *ans = head;

    if(k==1 || head == NULL)return head;
    while(head){
        ct++;
        if(ct == k){
            ans = head;
        }
        if(ct%k == 0){
            if(prev) prev->next = head;
            prev = head->next;
            head = start;
            reverse(start, prev, k);
            start = head->next;
            prev = head;
        }
        head = head->next;
    }
    return ans;
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