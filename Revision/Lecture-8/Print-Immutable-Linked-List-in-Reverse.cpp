// https://leetcode.com/discuss/interview-question/124617/Print-out-an-immutable-singly-linked-list-in-reverse/
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

class ImmutableListNode {
public:
    void printValue(); // print the value of the node.
    ImmutableListNode* getNext(); // return the next node.
};
 
void printLinkedListInReverse(ImmutableListNode *head){
    if (head){
        printLinkedListInReverse(head->getNext());
        head->printValue();
    }
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