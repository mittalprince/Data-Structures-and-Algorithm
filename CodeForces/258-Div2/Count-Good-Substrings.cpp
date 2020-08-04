// https://codeforces.com/contest/451/problem/D
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007


int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    string s;
    cin>>s;

    ll ct[2][2]={0}; // i->a,b, j->even,odd;
    
    ll odd=0, even=0;

    for(int i=0; i<s.length(); i++){
        odd++;
        if(i&1){ // add at even pos
            odd += ct[s[i]-'a'][0]; // agr 6 pos par add kia toh 4,2.. pos par same char ka count check karegenge as (6-4+1 -> will give odd len string), so ct[][0] liya
            even += ct[s[i]-'a'][1];
            ct[s[i]-'a'][0]++; // as we add a char at even pos so count of a/b will incrment in even col
        }
        else{ // add at odd pos
            odd += ct[s[i]-'a'][1]; // agr odd pos par add kia toh total odd ka count odd pos par kitna same char hai utne ke count se badega
            even += ct[s[i]-'a'][0]; // agr even pos par add kia toh total even ka count even pos par kitne same char utne ke count se badega
            ct[s[i]-'a'][1]++; // as we add a char at odd pos so count of a/b will incremnt  in odd col.
        }
    }

    cout<<even<<" "<<odd<<endl;
    return 0;
}