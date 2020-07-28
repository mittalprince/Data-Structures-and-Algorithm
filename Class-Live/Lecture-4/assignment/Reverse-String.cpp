#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void reverseString(vector<char>&arr){
    int n=arr.size();
    int s=0, e=n-1;
    while(s<e){
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

int main(){
    int n;
    cin>>n;
    vector<char> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }   
    reverseString(arr);
    return 0;
}