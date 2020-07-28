#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<int> relativeSortArray(vector<int>&arr1, vector<int>&arr2){
    int freq[1001] = {0};
    for (int i = 0; i < arr1.size(); i++)
    {
        freq[arr1[i]]++;
    }
    int k = 0;
    for (int i = 0; i < arr2.size(); i++)
    {
        int ct = freq[arr2[i]];
        while (ct--)
        {
            arr1[k++] = arr2[i];
        }
        freq[arr2[i]] = 0;
    }

    for (int i = 0; i <= 1000; i++)
    {
        while (freq[i]--)
        {
            arr1[k++] = i;
        }
    }
    return arr1;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr1(n), arr2(m);
    ip(arr1, n);
    ip(arr2, m);
    arr1 = relativeSortArray(arr1, arr2);
    op(arr1,n);
    return 0;
}