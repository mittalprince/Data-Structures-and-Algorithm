#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 200005

int main(){
    ll ct[MAX]={0};
    string s;
    cin>>s;
    int m,n;
    cin>>m;
    n = s.length();
    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        ct[x-1]++;
    }
    for(int i=0; i<n/2; i++){
        if(i>0) ct[i] += ct[i-1];
        ct[i] = ct[i]&1;
        if(ct[i]){
            swap(s[i], s[n-i-1]);
        }
    }
    cout<<s<<endl;
    return 0;
}