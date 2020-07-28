#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
#define MAX 1000001000000

string recipe;
ll given_bread, given_sausage, given_cheese;
ll bread_price, sausage_price, cheese_price;
ll total_amt, ans;
ll bread_req, sausage_req, chesse_req;
ll total_bread_amt, total_sausage_amt, total_chesse_amt;

ll solve(){

    ll s=0, e=MAX;
    ans=0;
    
    for(char i: recipe){
        if(i=='B') bread_req++;
        else if(i=='S') sausage_req++;
        else chesse_req++;
    }

    while(s<=e){
        ll mid = (s+e)/2;
        total_bread_amt = (mid*bread_req - given_bread)*bread_price;
        total_bread_amt = (total_bread_amt<0)?0:total_bread_amt;

        total_sausage_amt = (mid*sausage_req - given_sausage)*sausage_price;
        total_sausage_amt = (total_sausage_amt<0)?0:total_sausage_amt;

        total_chesse_amt = (mid*chesse_req - given_cheese)*cheese_price;
        total_chesse_amt = (total_chesse_amt<0)?0:total_chesse_amt;

        ll total_req_amt = total_chesse_amt+total_sausage_amt+total_bread_amt;
        if(total_req_amt == total_amt){
            return mid;
        }
        else if(total_req_amt < total_amt){
            ans=mid;
            s=mid+1;
        }
        else e=mid-1;
    }

    return ans;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    // cin>>t;
    while(t--){
        cin>>recipe;
        cin>>given_bread>>given_sausage>>given_cheese;
        cin>>bread_price>>sausage_price>>cheese_price;
        cin>>total_amt;
        cout<<solve()<<endl;
    }
    return 0;
}