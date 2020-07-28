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

    ListNode():val(0),next(NULL){}
};

int length(ListNode *head){
    int ans=0;
    while(head){
        head = head->next;
        ans++;
    }
    return ans;
}

vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int n=length(head);
    vector<ListNode*> ans;

    int remElement = n%k;
    int len_of_seg = n/k;
    int parts = n/k; // tell we have less elemnt than k

    if(parts==0){
        for(int i=0; i<k; i++){
            if(head){
                ListNode *temp = head->next;
                head->next = NULL;
                ans.push_back(head);
                head = temp;
            }
            else{
                ans.push_back(NULL);
            }
        }
    }
    else{
        while(head){
            ans.push_back(head);
            int x = remElement>0?1:0;
            remElement--;
            for(int i=1; i<len_of_seg+x; i++){
                head = head->next;
            }
            ListNode *temp = head->next;
            head->next = NULL;
            head = temp;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}