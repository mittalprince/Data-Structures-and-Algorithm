#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
#define pi 3.14159265359

void solve(){
    double b, c;
    cin >> b >> c;

    double ans=0, s=0, e=pi/2;    
    while(s<=e){
        double mid = (s+e)/2;
        float num1 = (2 * mid + b) * sin(mid);
        float num2 = cos(mid) * (mid * mid + b * mid + c);
        float val = num1 - num2;
        if (val == 0.000000000000000){
            ans = mid;
            break;
        }
        else if (val < 0){
            ans = mid;
            s = mid;
        }
        else{
            e = mid;
        }
    }
    ans = (ans*ans + b*ans + c)/sin(ans);
    cout<<fixed<<setprecision(10)<<ans<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}