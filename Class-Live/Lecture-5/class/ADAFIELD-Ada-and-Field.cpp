// In case k is not present in the set container, the function returns an iterator pointing to the immediate next 
// element which is just greater than k.

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    fstIO;
    int t;
    cin>>t;
    while(t--){
        ll n,m,q;
        cin>>n>>m>>q;
        //here we use multiset as two segment can have same val
        multiset<ll> sx, sy, x ,y;
        // sx gives the largest segment of x val
        // yx gives the largest segment of y val
        // x -> store all segment of x; iniially we have two segment 0,n
        // y store all segment of y; iniially we have two segment 0,n

        // why we take x & y as when we divide a segment into two segment
        // assumw we have (y) 0 - 5 ka ek seg but jab mein 3 par line dalunga toh 
        // seg abb 0-3 & 3-5 ho jaeyga toh hume yeh pta hona chahiyeki phela vala konsa segment hai 
        // jo iss segment ke se affect honge so we store all
        // and erase 0-5 from


        sx.insert(n); // currently largest x seg val
        sy.insert(m);

        x.insert(0); x.insert(n); // currently all posiible segments (i.e where seg occcur now)
        y.insert(0); y.insert(m);

        for(ll i=0; i<q; i++){
            ll a,b;
            cin>>a>>b;
            if(a==0){ // voh x segment ki baat kar rha hai 
                if(x.find(b) != x.end()){
                   cout<<(*(--sx.end()))*(*(--sy.end()))<<endl; 
                   continue;
                }
                // here we find just upper and lower val of b as we have now seg at b 
                // so just upper to b and just lower b will affect 
                auto small = x.lower_bound(b);
                small--;
                auto large = x.upper_bound(b);

                x.insert(b);
                sx.erase(sx.find(*large-*small)); // erase prev seg of lagre to small
                sx.insert(b-*small); // insert new seg from b to smll
                sx.insert(*large-b); // insert new seg from large top b

                cout<<(*(--sx.end()))*(*(--sy.end()))<<endl; // preint prod of lagest seg val of sx & y
            }
            else{
                if(y.find(b) != y.end()){
                   cout<<(*(--sx.end()))*(*(--sy.end()))<<endl; 
                   continue;
                }
                auto small = y.lower_bound(b);
                small--;
                auto large = y.upper_bound(b);

                y.insert(b);
                sy.erase(sy.find(*large - *small)); // erase prev seg of lagre to small
                sy.insert(b - *small);              // insert new seg from b to smll
                sy.insert(*large - b);              // insert new seg from large top b

                cout<<(*(--sx.end()))*(*(--sy.end()))<<endl; // preint prod of lagest seg val of sx & y
            }
        }
    }
    return 0;
}