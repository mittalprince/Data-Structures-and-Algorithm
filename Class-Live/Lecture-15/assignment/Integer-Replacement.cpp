#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int integerReplacement(int n) {
    int count=0;
    long N=n;
    while(N>1)
    {
        if(N%2==0) N/=2;
        else
        {
            if(((N+1)/2)%2==0 && (N+1)/2>3) N++;
            else N--;
        }
        count++;
    }       
    return count;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}