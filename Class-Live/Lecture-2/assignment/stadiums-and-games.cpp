#include<iostream>
#include<climits>
#include<set>
#include<cmath>
using namespace std;
typedef long long ll;
#define MAX 63
#define M 1e10

// logic we are given total matach played, you have to tell the total no possible teams in sorted order
// for odd teams M, we have M(M-1)/2 (i.e knockout)
// for even team M, we play M/2 matck until M become odd

// for each team m-> m/2-> m/4-> m/8-> .....
// we see at each step m divides by 2 and it continues untill m become odd
// so at any stage say m become any odd no, assume divide by 2 happend d time so (2^d)
// hence total match played will be M*(M-1)/2 + m*(2^d-1)
// then totsl team will be M*2^D

/*
Suppose the "divide-by-two" stage happens exactly D times, and the round robin happens with M people.
Then, the number of games held is: 
We would like that 
This is an equation with two variables -- to solve it, we can enumerate the value of one of the variables and calculate the value of the other one. We cannot enumerate the possible values of M, since M can vary from 1 to 10^9. However, we can enumerate D, since the number scales exponentially with D -- that is, we should only enumerate 0 ≤ D ≤ 62.
Thus, the equation is reduced to 
Since this function is increasing, this can be solved via binary search on M.
*/
int main(){
    ll n;
    cin>>n;
    set<ll> ans;
    for(int i=0; i<MAX; i++){
        ll D = pow(2,i)-1;
        // i.e means all match played with even no teams
        // m=1 1*(0)/2 + m*(2^d)
        if(n == D){
            ans.insert(D+1);
            continue;
        }
        ll s=0, e=M;
        while(s<=e){
            ll mid = (s+e)/2;
            ll t=mid;
            t*=(mid-1);
            t /= 2;
            
            if(D!=0 && mid > (LLONG_MAX/D)){
                t=LLONG_MAX;
            }
            else{
                t += mid*D;
            }
            if(t==n){
                // here we check if m is odd, if yes then we push mid
                // as we assume that the round robin happens with M people.
                // i.e odd
                if(mid&1){
                    ans.insert(mid*(D+1));
                }
                break;
            }
            if(t<n){
                s = mid+1;
            }
            else e=mid-1;
        }
    }
    if(ans.empty()){
        cout<<"-1";
    }
    else{
        for(ll i: ans)
            cout<<i<<" ";
    }
    cout<<endl;
}


/*
#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;
typedef unsigned long long int ll;
#define BITS 63

int main(){
    ll D=0, n;
    cin>>n;
    vector<ll>ans;
    for(int i=0; i<BITS; i++){
        D = (1ll<<i)-1;
        ll l=1, r=min((ll) 1e9, n / (D + 1) + 5);

        while(l<=r){
            ll m = (l+r)/2;
            ll mid = 2*m-1;
            ll temp = ((mid-1)*mid)/2+(mid*D);
            if(temp == n){
                ans.push_back(mid*(1ll<<i));
                break;
            }
            else if(temp < n) l=m+1;
            else r=m-1;
        }
    }
    if(ans.empty()){
        cout<<"-1\n";
    }
    else{
        sort(ans.begin(), ans.end());
        for(ll i: ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
*/