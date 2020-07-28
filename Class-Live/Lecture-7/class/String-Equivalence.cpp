#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void stringEquivalence(int n, int i, string out, char max_char){
    if(i==n){
        cout<<out<<endl;
        return;
    }

    for(char c='a'; c<=max_char; c++){
        out += c;
        if(c == max_char){
            stringEquivalence(n, i+1, out, max_char+1);
        }
        else stringEquivalence(n, i+1, out, max_char);
        out.pop_back();
    }
}
int main(){
    int n;
    cin>>n;
    stringEquivalence(n, 0, "", 'a');
    return 0;
}