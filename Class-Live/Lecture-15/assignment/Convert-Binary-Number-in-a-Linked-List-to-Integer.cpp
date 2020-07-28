#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int val(ListNode *head, int &len, int &idx){
    if(head == NULL){
        idx = len;
        return 0;
    }
    len++;
    int ans = val(head->next, len, idx);
    if(head->val == 1){
        ans += (1<<(len-idx));
    }
    idx--;
    return ans;
}

int getDecimalValue(ListNode* head) {
    int ans=0, idx=0, len=0;
    ans = val(head, len, idx);
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}