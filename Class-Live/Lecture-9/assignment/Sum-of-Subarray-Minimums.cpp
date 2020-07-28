#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

/*
We will use a stack and left and right array. Here, the stack will store the index of the current min element. 
Left[i] will store the index of min element to the left of element, 
if no min element exist to left of it we will initialize it to -1. 
In same way, right[i] will store the index of min element to the right of element, 
if no min element exist to right of it we will initialize to size of array.


not for a given arr[i], it contribute to sum is : arr[i]*(i-left[i])*(right[i]-i)
as left[], right[] denote for a given arr[i], usse phela chota no kiss index par hai
so from i to left[i] tak ki left side ki sabhi subarry mein arr[i] include hoga as it will be min
similllary, right[i] to i tak ki right subarr mein arr[i] include hoga as it will min in this range

so total contribution is : arr[i]*(i-left[i])*(right[i]-i)
*/
int sumSubarrayMins(vector<int>& A) {
    int n=A.size();
    if(n==0) return 0;

    stack<int>s;
    vector<int>left(n,-1), right(n, n);

    for(int i=0; i<n; i++){
        while(!s.empty() && A[s.top()]>=A[i]) s.pop();

        if(!s.empty())left[i]=s.top();
        s.push(i);
    }

    s=stack<int>();
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && A[i]<A[s.top()]){
            s.pop();
        }
        if(!s.empty()){
            right[i]=s.top();
        }
        s.push(i);
    }

    int ans=0;
    for(int i=0; i<n; i++){
        ans += (((i-left[i])*(right[i]-i))%mod)*(A[i]%mod);
        ans %=mod;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}