#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

// logic is 
// for a given element x, phela usse chota jitni element hai sab ane chahiye then usse bade ayenegetabhi stack sortable hai 
// so to check given stack is sortable or not we use same trick
// and for rest of element we print them in dec order

int main(){
    int n,k;
    cin>>n>>k;
    stack<int>s;
    s.push(n+1); // we add this elemnmt as when our all k element end then we start seq fron n to n-k in dec order
    int ptr=1;
    int arr[n];
    for(int i=0; i<n; i++){
        if(i<k){
            cin>>arr[i];
        }
        else{
            // add a one less than top (because of dec nature)
            arr[i] = s.top()-1;
        }
        s.push(arr[i]);
        // we use ptr to check for a given element usse chota sare element a gaye ki nahi
        // when there is one in stack and ptr is 1 i.e we pop stack and incr ptr
        // now ptr is i.e we have all elemnt samller than 2 
        // same process goes until the loop end
        while(!s.empty() && s.top() == ptr){
            s.pop();
            ptr++;
        }
    }
    if(!s.empty()){
        cout<<"-1\n";
    }
    else{
        op(arr, n);
        cout<<endl;
    }
    return 0;
}