// https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/
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

void merge(vector<int> &A, vector<int> &B) {
    int n1 = A.size();
    int n2 = B.size();
    
    int i=0, j=0;
    
    while(i<n1 && j <n2){
        if(A[i] > B[j]){
            A.insert(A.begin()+i, B[j]);
            j++;
            n1++;
        }
        i++;
    }
    
    if(j < n2){
        A.insert(A.end(), (B.begin()+j), B.end());
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