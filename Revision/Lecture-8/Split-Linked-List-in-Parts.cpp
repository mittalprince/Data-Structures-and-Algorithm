// https://leetcode.com/problems/split-linked-list-in-parts/
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

int length(ListNode *head){
    int len=0;
    while(head){
        len++;
        head=head->next;
    }
    return len;
}
vector<ListNode*> splitListToParts(ListNode* head, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = length(head);
    vector<ListNode*>ans;

    int remElmt = n%k;
    int len_of_seg = n/k;
    int parts = n/k;

    if(parts==0){
        for(int i=0; i<k; i++){
            if(head){
                ListNode *next = head->next;
                head->next=NULL;
                ans.push_back(head);
                head = next;
            }
            else ans.push_back(NULL);
        }
    }
    else{
        while(head){
            ans.push_back(head);
            int x = remElmt>0?1:0;
            remElmt--;
            for(int i=1; i<len_of_seg+x; i++)
                head=head->next;

            ListNode *next = head->next;
            head->next=NULL;
            head=next;
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