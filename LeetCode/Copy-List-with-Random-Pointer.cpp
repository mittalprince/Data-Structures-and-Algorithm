// https://leetcode.com/problems/copy-list-with-random-pointer/
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

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(head==NULL)return head;
    Node *curr=head;

    while(curr){
        Node *temp = curr->next;
        curr->next = new Node(curr->val);
        curr->next->next = temp;
        curr=temp;
    }

    Node *ans = head->next;
    curr = head;

    while(curr){
        Node *temp = curr->next;
        if(curr->random){
            temp->random = curr->random->next;
        }
        curr = temp->next;
    }

    curr=head;
    while(curr){
        Node *temp = curr->next;
        curr->next = temp->next;
        curr = curr->next;

        if(curr){
            temp->next = curr->next;
        }
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