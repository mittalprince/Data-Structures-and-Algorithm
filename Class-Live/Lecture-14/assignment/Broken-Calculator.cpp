#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
On a broken calculator that has a number showing on its display, we can perform two operations:

Double: Multiply the number on the display by 2, or;
Decrement: Subtract 1 from the number on the display.
Initially, the calculator is displaying the number X.

Return the minimum number of operations needed to display the number Y.
*/

/*
Logic:
Here we backtrack the problem in reverse meanner mweans we change y to x
then we have 2 operation, divide by 2 or add 1

Considering how to change Y to X
Opertation 1: Y = Y / 2 if Y is even
Opertation 2: Y = Y + 1

If Y <= X, we won't do Y / 2 anymore.
We will increase Y until it equals to X, beacuse we this we add (X-Y) into and at final step
*/
int brokenCalc(int X, int Y) {
    int ans=0;

    while(Y>X){
        ans++;
        if(Y&1){
            Y++;
        }
        else Y/=2;
    }
    return ans + (X-Y);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}