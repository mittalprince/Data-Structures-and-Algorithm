#include<iostream>
using namespace std;
typedef long long ll; 

int arrangeCoins(int n){
    if(!n) return n;
    ll s=0, e=n;

    while(s<=e){
        ll mid = s+(e-s)/2;
        ll t = ((1+mid)*mid)/2;
        if(t==n) return mid;
        if(t<n) s=mid+1;
        else e=mid-1;
    }
    ll t = ((1+s)*s)/2;
    return (t==n)?s:s-1;
}

int main(){
    int n;
    cin>>n;
    cout<<arrangeCoins(n)<<endl;
    return 0;
}