// https://leetcode.com/problems/linked-list-components/
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

    ListNode(int val):val(val),next(NULL){}
};

int numComponents(ListNode* head, vector<int>& G) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int freq[10001]={0};

    for(int i: G){
        freq[i]++;
    }

    int component=0;
    while(head){
        if(freq[head->val] and (head->next==NULL or !freq[head->next->val])){
            component++;
        }    
        head=head->next;
    }

    return component;
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