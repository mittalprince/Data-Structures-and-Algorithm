#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;

int main(){
    ll x,n;
    cin>>x>>n;

    if(n>=5){
        cout<<"1\n";
    }
    else{
        ll d = x%10;
        ll fact=1;
        for(int i=2; i<=n; i++){
            fact = (fact%10 *i%10);
            fact %= 10;
        }

        ll ans = pow(d, fact);
        cout<<(ans%10)<<endl;
    }
}