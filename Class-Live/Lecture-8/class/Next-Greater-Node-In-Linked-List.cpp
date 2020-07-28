#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class ListNode{
    public:
    int val;
    ListNode *next;

    ListNode():val(0),next(NULL){}
};

ListNode* reverse(ListNode *head){
    ListNode *prev=NULL, *curr=head, *next=NULL;
    
    while(curr){
        next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

vector<int> nextLargerNodes(ListNode* head) {
    vector<int>ans;
    if(head==NULL) return ans;
    
    head = reverse(head);
    stack<int> s;
    
    while(head){
        while(!s.empty() && s.top()<= head->val){
            s.pop();
        }
        if(s.empty()) ans.push_back(0);
        else ans.push_back(s.top());
        s.push(head->val);
        head = head->next;
    }
    std::reverse(ans.begin(),ans.end());
    return ans;
}

vector<int> nextLargerNodes(ListNode* head) {
    vector<int> ans;
    
    while(head){
        ListNode* temp = head;
        while(temp && temp->val<=head->val){
            temp = temp->next;
        }
        if(temp) ans.push_back(temp->val);
        else ans.push_back(0);
        
        head = head->next;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}