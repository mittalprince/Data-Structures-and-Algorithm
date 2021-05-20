// https://www.geeksforgeeks.org/find-the-missing-number-in-a-sorted-array/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

/*
Given a list of n-1 integers and these integers are in the range of 1 to n. 
There are no duplicates in list. One of the integers is missing in the list. 
Write an efficient code to find the missing integer. 

Input : arr[] = [1, 2, 3, 4, 6, 7, 8]
Output : 5

Input : arr[] = [1, 2, 3, 4, 5, 6, 8, 9]
Output : 7

An efficient solution is based on the divide and conquer algorithm that we have seen in binary search, 
the concept behind this solution is that the elements appearing before the missing element will have 
ar[i] – i = 1 and those appearing after the missing element will have ar[i] – i = 2.
*/

int search(vector<int>&arr){
    int n = arr.size();
    int s=0, e=n-1;

    while(s<e){
        int mid = (s+e)/2;
        if (arr[s]-s != arr[mid]-mid) e=mid;
        else if(arr[e]-e != arr[mid-mid]) s = mid;
    }
    return arr[s]+1;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    ip(arr, n);
    cout<<search(arr)<<endl;
    return 0;
}