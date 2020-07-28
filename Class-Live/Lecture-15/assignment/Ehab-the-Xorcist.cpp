#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

ll u,v;

void solve(){
    // case 1. when u>v or u & v  have diff parities(means rightmost bit are diff, but its not possible)
    // as when we have 1 in u in rightmost bit, means we have number that have odd no of ones, and when we also add
    // odd no of ones, it also leaves 1, so both no have same parities
    if(u>v || ((u&1) != (v&1))){
        cout<<"-1\n";
        return;
    }
    // case 2, whe have u=v and both are 0, the ans is 0 itself
    if(u==v && u==0){
        cout<<"0\n";
        return;
    }
    // case 3, when u=v but they are not zero then u itlsef the ans
    if(u==v && u != 0){
        cout<<"1\n"<<u<<endl;
        return;
    }
    // a+b = (a^b) + 2*(a&b) -> a&b = ((a+b)-(a^b))/2 -> v-u/2
    ll x = (v-u)/2;
    //If 𝑥 has a one in some bit, 𝑎 and 𝑏 must both have ones, so 𝑎⊕𝑏=𝑢 must have a 0.
    //So, if there's a bit where both 𝑥 and 𝑢 have a one, that is to say if x&u != 0, you can't find such 𝑎 and 𝑏, and the length will be 3,
    //as x is and and u is xor so it can not possible we have a set bit in both

    if(x&u){
        cout<<"3\n";
        cout<<x<<" "<<x<<" "<<u<<endl;
        return;
        // (u^x^x) -> u
        // u+x+x -> v
    }
    else{
        cout<<"2\n";
        cout<<x<<" "<<u+x<<endl;
        return;
        // (u+x)^x -> u
        // (u+x+x) -> v
    }
}

int main(){
    cin>>u>>v;
    solve();
    return 0;
}