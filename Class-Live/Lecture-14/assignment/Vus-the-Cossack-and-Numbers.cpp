#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    int n;
    cin>>n;
    double arr[n];
    ll a[n], sum=0;

    for(int i=0; i<n; i++){
        cin>>arr[i];
        a[i] = floor(arr[i]);
        sum += a[i];
    }

    for(int i=0; i<n; i++){
        if(sum<0 && ceil(arr[i]) != arr[i]){ // ceil(arr[i]) != arr[i], when we have pure int, we do nothing
            a[i]++;
            sum++;
        }
    }

    for(int i=0; i<n; i++){
        cout<<a[i]<<endl;
    }
    return 0;
}