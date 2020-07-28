// https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/
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

vector<int> getRow(int A) {
    vector<int> prev;
    prev.push_back(1);
    if(A==0){
        return prev;
    }
    for(int i=0; i<A; i++){
        vector<int>next;
        next.push_back(1);
        for(int j=0; j<prev.size()-1; j++){
            next.push_back(prev[j]+prev[j+1]);
        }
        next.push_back(1);
        prev = next;
    }
    return prev;
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