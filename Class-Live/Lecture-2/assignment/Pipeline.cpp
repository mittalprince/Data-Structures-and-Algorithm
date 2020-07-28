#include<iostream>
using namespace std;
typedef long long ll;
typedef long long unsigned llu;

ll func(ll k){
    return (k*(k+1))/2;
}
int main(){
    ll n;
    ll k;
    cin>>n>>k;
    ll total_max = func(k);
    if(n==1){
        cout<<"0\n";
        return 0;
    }
    if(n<=k){
        cout<<"1\n";
        return 0;
    }
    /*
    total_max mein k-1 isliye sub kiya qki har ek spilter kam output dega 
    qki uska ek output next ke liye input banega, but jo last spliter hoga uska vahi outpur rahega
    jitna voh de sakta hai so (k-1)
    */
    if(total_max-(k-1)<n){
        cout<<"-1\n";
        return 0;
    }

    ll s=1, e=k;
    ll ans=0;
    while(s<=e){
        ll mid = (e+s)/2;
        /*
        sum(l,r) = sum(r)-sum(l-1)
        simillarly total_max mein se (k-mid) ke pipe hta doo jitna bacha usme se (mid-1) ho kam kar doo
        same as logic (for k-1)
        */
        ll  temp = total_max - func(k-mid) - (mid-1);
        /*
        temp -> now mein kitna output de sakta hoo
        agr yeh jayda hai n se toh kamm karna hai uska liye func(k-mid) kam jayda karna hoga (taki diff kam rahe)
        qki total_max fix hai, so func(k-mid) jayda hoga agr mid kam hoga so e=mid-1
        */
        if(temp >= n){
            ans=mid;
            e=mid-1;
        }
        else s=mid+1;
    }
    cout<<ans<<endl;
}