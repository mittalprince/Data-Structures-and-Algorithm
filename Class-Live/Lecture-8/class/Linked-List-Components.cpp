#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class ListNode{
    public:
    int val;
    ListNode *next;

    ListNode(int val):val(val),next(NULL){}
};

int numComponents(ListNode* head, vector<int>& G) {
    int freq[10001]={0};
    for(int i: G){
        freq[i]++;
    }
    int component=0;
    while(head){
        if(freq[head->val] && (head->next == NULL || !freq[head->next->val])){
            component++;
        }
        head = head->next;
    }
    return component;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}