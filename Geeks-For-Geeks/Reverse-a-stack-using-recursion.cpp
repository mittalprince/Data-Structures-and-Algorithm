#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

stack<int>s;

void insertAtBottom(int x){
    if(s.empty()) s.push(x);
    else{
        int a=s.top();
        s.pop();
        insertAtBottom(x);
        s.push(a);
    }
}
void reverse(){
    if(s.empty()) return;

    int x=s.top();
    s.pop();
    reverse();
    insertAtBottom(x);
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        s.push(x);
    }
    reverse();
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}