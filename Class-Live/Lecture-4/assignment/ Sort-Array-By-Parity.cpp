#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<int> sortArrayByParity(vector<int> &A)
{
    int n = A.size();
    int s = 0, e = n - 1;

    // while(s<e){
    //     if(A[s]&1){
    //         swap(A[s], A[e]);
    //         e--;
    //     }
    //     else if(A[e]%2==0){
    //         swap(A[e], A[s]);
    //         s++;
    //     }
    //     else {
    //         s++;
    //         e--;
    //     }
    // }

    while (s < e)
    {
        if (A[s] & 1 && A[e] % 2 == 0)
        {
            swap(A[s], A[e]);
        }

        if (A[s] % 2 == 0)
            s++;
        if (A[e] & 1)
            e--;
    }
    return A;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    ip(arr, n);
    arr = sortArrayByParity(arr);
    op(arr,n);
    return 0;
}