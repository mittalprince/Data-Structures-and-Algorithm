#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int titleToNumber(string A) {
    int res=0;
    int i=0;
    while(A[i] != '\0'){
        res = res*26+(A[i]-'A'+1);
        i++;
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}