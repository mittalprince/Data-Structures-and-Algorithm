#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int ans = INT_MAX;

void findPairs(int a, int b, int steps){
    if(a==1 && b==1){
        ans = min(ans, steps);
    }
    if(a-b>0) findPairs(a-b, b, steps+1);
    if(b-a>0) findPairs(a, b-a, steps+1);
}

int main(){
    int n;
    cin>>n;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    for(int i=1; i<n; i++){
        findPairs(i, n-i, 1);
    }
    cout<<ans<<endl;
    return 0;
}