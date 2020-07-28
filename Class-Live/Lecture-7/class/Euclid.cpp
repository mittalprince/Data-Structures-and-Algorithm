#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int eea(int a, int b, int &x, int &y){
    if(b==0){
        x=1, y=0;
        return a;
    }
    int x1,y1;
    int ans = eea(b, a%b, x1, y1);
    x = y1;
    y = x1-(a/b)*y1;
    cout<<x<<" "<<y<<endl;
    return ans;
}
int main(){
    int a,b,x,y;
    cin>>a>>b;
    cout<<gcd(a, b)<<endl;
    cout<<eea(a,b, x,y)<<endl;
    return 0;
}