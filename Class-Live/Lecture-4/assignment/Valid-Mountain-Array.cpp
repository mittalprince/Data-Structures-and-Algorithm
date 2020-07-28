#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

bool validMountainArray(vector<int> &A)
{

    int n = A.size();
    int i = 0;
    while (i < n - 1 && A[i] < A[i + 1])
        i++;

    if (i == 0 || i == n - 1)
        return false;

    while (i < n - 1 && A[i] > A[i + 1])
        i++;

    return i == n - 1;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    ip(arr, n);
    if(validMountainArray(arr))cout<<"true\n";
    else cout<<"false\n";
    return 0;
}