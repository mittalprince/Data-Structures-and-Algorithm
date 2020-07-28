
/*
in stack we store indexes

1. Push the current height into the stack if its val is higher than stack top height
2. pop all the bars of heigth greater (when pop operation occur we cal area of region with current bar as min height)

use two formula for cal area
1. when stack is empty  = ht*i
2. when stack is not empty() = a[top]*(i-s.top()-1)
    where i = right most smaller element
    s.top() prev top (leftmost smaller)



if stack is empty push the curr elemnt
else 
if incoming val is less arr[s.top()] then we pop and store its height
now we we check is stack is empty or not
if yes the area = ht*i
else a[top]*(i-s.top()-1)
*/
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve(int n){
    ll arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    stack<int> s;
    ll area=0;
    int i;
    for(i=0; i<n;){
        if(!s.empty() && arr[i] <= arr[s.top()]){
            ll ht = arr[s.top()];
            s.pop();
            if(s.empty()){
                //since now stack become empty, so its has no left most smaller
                // so area will be ht* current i
                area = max(area, ht*i);
            }
            else{
                // here for ht we find leftmost smaller which is now stack top
                // and right most smaller which is current elemnt as arr[i]<= ht
                area = max(area, ht*(i-s.top()-1));
            }
        }
        else{
            s.push(i++);
        }
    }
    
    while(!s.empty()){
        ll ht = arr[s.top()];
        s.pop();
        if(s.empty()){
            area = max(area, ht*i);
        }
        else{
            area = max(area, ht*(i-s.top()-1));
        }
    }
    cout<<area<<endl;
}
int main(){
    int n;
    cin>>n;
    while(n!=0){
        solve(n);
        cin>>n;
    }
    return 0;
}