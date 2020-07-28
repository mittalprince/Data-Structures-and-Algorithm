#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, temp;
        cin>>n;
        map<int, int> m;
        int mx = 0;
        for(int i=0; i<n; i++){
            cin>>temp;
            m[temp]++;
            mx = max(mx, m[temp]);
        }
        int sz = m.size();
        if(mx == m.size()) cout<<mx-1<<endl;
        else cout<<min(mx, sz)<<endl;
    }
    return 0;
}