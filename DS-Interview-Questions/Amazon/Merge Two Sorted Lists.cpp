// https://leetcode.com/problems/merge-two-sorted-lists/
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

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){} 
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}                                                                                                                            *
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(l1 == NULL){
        return l2;
    }
    if(l2 == NULL){
        return l1;
    }
    ListNode *ans = NULL, *temp1;

    while(l1 && l2){
        if(l1->val <= l2->val){
            if(ans == NULL){
                ans = l1;
                temp1=l1;
            }
            else{
                temp1->next=l1;
                temp1=temp1->next;   
            }
            l1=l1->next;
        }
        else{
            if(ans == NULL){
                ans = l2;
                temp1=l2;
            }
            else{
                temp1->next=l2;
                temp1=temp1->next;   
            }
            l2=l2->next;
        }
    }

    if(l1){
        temp1->next=l1;
    }
    else{
        temp1->next=l2;
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