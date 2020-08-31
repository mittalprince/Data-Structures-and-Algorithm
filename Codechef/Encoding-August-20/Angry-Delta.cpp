// https://www.codechef.com/ENAU2020/problems/ECAUG202
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        ll n;
        cin >> n;

        vector<ll> A(n);
        ll res = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
            if (A[i] % 2 == 0)
                res += A[i];
        }
        cout << res << endl;
    }
    return 0;
}