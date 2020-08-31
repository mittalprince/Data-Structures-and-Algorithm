// https://www.codechef.com/ENAU2020/problems/ECAUG204
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        sort(A, A+n);
        bool f=true;
        for(int i=0; i<n-1; i++){
            if(A[i]==A[i+1]){
                f=false;
                break;
            }
        }

        if(f){
            cout<<"Yes\n";
        }
        else cout<<"No\n";
    }
    return 0;
}