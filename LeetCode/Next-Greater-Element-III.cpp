#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the 
same digits existing in the integer n and is greater in value than n. 
If no such positive 32-bit integer exists, you need to return -1.
*/

int nextGreaterElement(int N) {
    string a = to_string(N);
    int n=a.length();

    int i,j;
    for(i=n-2; i>=0; i--){
        if(a[i]<a[i+1]) break;
    }
    if(i==-1){
        return -1;
    }

    j=i+1;
    while(j<n && a[j]>a[i]) j++;
    swap(a[i], a[j-1]);
    sort(a.begin()+i+1, a.end());
    long long ans= stoll(a);

    return ans>INT_MAX?-1:ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}