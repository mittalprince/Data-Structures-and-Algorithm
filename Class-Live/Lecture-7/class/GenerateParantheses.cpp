#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void genPattern(int n, int i, char *out, int open, int close){
    if(i == (2*n)){
        out[i] = '\0';
        cout<<out<<endl;
        return;
    }
    if(open > close){
        out[i] = ')';
        genPattern(n, i+1, out, open, close+1);
    }
    if(open < n){
        out[i] = '(';
        genPattern(n, i+1, out, open+1, close);
    }
}
int main(){
    int n;
    cin>>n;
    char a[10000];
    genPattern(n, 0, a, 0, 0);
    return 0;
}