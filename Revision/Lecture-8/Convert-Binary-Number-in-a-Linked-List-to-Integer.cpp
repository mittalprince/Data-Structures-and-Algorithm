// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
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

int solve(ListNode *head, int &ans){
    if(head==NULL){
        return 0;
    }    
    int idx = solve(head->next, ans);
    if((head->val)&1){
        ans += (1<<idx);
    }
    return idx+1;
}

int getDecimalValue(ListNode* head) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans=0;
    solve(head, ans);
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