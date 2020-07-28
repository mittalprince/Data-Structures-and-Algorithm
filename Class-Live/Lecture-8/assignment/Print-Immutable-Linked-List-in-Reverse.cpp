#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);


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
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}