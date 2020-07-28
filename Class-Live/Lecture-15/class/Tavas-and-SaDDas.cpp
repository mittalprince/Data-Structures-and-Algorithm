#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

string s;

ll solve(){
    int len = s.length();

    ll ans = (1<<len)-2; // total no of lucky no possible upto (len-1)

    // now we find the pos of s when we consider only len length lucky numbers
    // if we got a 7 at any pos means, if we place 4 at this and all prev pos can have now 2 options (7/4)
    ll pos=0;
    for(int i=len-1; i>=0; i--){
        if(s[i] == '7'){
            ans += (1<<pos);
        }
        pos++;
    }
    return ans+1;
}
int main(){
    cin>>s;
    cout<<solve()<<endl;
    return 0;
}