// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/
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

int removeDuplicates(vector<int> &A) {
    int n = A.size();
    if(!n){
        return 0;
    }
    for(int i=0; i<A.size()-1; i++){
        int j=1;
        while(A[i] == A[i+1] && i<A.size()-1){
            j++;
            i++;
        }
        
        // cout<<i<<" "<<j<<endl;
        if(j>2){
            A.erase(A.begin()+i-j+2, A.begin()+i);
            i = i-j+2;
        }
    }
    
    return A.size();
    
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