#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n,d;
ll arr[100005];

void solve(){
    ll amount=0;
    for(int i=0; i<n; i++){
        if(arr[i] == 0){
            // go bank and make amt to zero to check whether given seq of transaction is valid or not
            // means try to make as much as less amt so that it didn't exced d
            if(amount<0) amount=0;
            // here we check amt<0, as she can deposit only not withdraw
            // so when amt >0 and i set amt =0 means i withdraw but it is not possible
        }
        else{
            amount += arr[i];
            if(amount > d){
                cout<<"-1\n";
                return;
            }
        }
    }

    // if default fail nahi hua, then i never make system to fail, so at every step i make optimal trasaction
    // make system valid such that it uses min visit of bank

    amount = 0;
    int total_visit=0;
    for(int i=0; i<n; i++){
        if(arr[i] == 0){
            if(amount<0) {
                amount=d;
                total_visit++;
            }
        }
        else{
            amount += arr[i];
            if(amount > d){
                amount=d;//if amt exced then i reset to d, as at each at add max amt when visit to bank
            }
        }
    }
    cout<<total_visit<<endl;
}

int main(){
    cin>>n>>d;
    ip(arr, n);
    solve();
    return 0;
}