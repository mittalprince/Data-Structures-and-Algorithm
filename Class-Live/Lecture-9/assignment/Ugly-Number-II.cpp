#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int nthUglyNumber(int n) {
    vector<int>ans(n);
    ans[0]=1;

    int p2=0, p3=0, p5=0;

    for(int i=1; i<n; i++){
        int t = min(ans[p2]*2, min(ans[p3]*3, ans[p5]*5));
        ans[i]=t;
        if(t == ans[p2]*2) p2++;
        if(t == ans[p3]*3) p3++;
        if(t == ans[p5]*5) p5++;
    }

    return ans[n-1];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}