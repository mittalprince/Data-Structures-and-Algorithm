// https://www.interviewbit.com/problems/sort-by-color/
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

void sortColors(vector<int> &A) {
    int l=0, mid=0, r=A.size()-1;
    while(mid<=r){
        switch(A[mid]){
            case 0:
                swap(A[l++], A[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(A[mid], A[r--]);
                break;
        }
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}