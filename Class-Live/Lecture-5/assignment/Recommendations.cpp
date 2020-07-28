#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

// question basically yeh kai hi mujhe n number given hai, jisme se kuch repaet ho rahe hai 
// mein har no ko +1 se increment kar saktu jiske liye t time lagta hai which is given in other arr
// now mujhe array ke no iss tarah update or say element ko increment karna hai, 
// ki sare element unique ho jaye, and the time required to perform this operation must be min

// Logic used: use multiset, and basically mein sabse jayda time lageyga jiss no ko change karne mein 
// mein usse chod ke baki jitne bache hai (jinki val uske equal thi) unke time ko add kar dunga
// aise mein har element ke liye jab taki mera pass sare unique nahi reh jate

// to find the max time for the same val no we use multiset as highest val stored at end

int main(){
    fstIO;
    ll n,temp=0;
    cin>>n;
    vector<ll>a(n), b(n);

    for(ll i=0; i<n; i++) cin>>a[i];
    for(ll i=0; i<n; i++) cin>>b[i];

    // store the pair (number, req time to change)
    vector<pair<ll, ll> >arr;
    for(ll i=0; i<n; i++){   
        arr.push_back({a[i], b[i]});
    }
    
    // we sort the arr so that humme yeh pta chal sakta ki konse konse consecutive element present taki hai
    // taki usme se ek ho rakhe aur baki ko increment kar de
    sort(arr.begin(), arr.end());
    
    // use multiset to store the time req to increment a no
    multiset<ll> s;

    // point yeh hai ki prev ka use hai ?
    // dekho qki mein arr ke element ko sirf incrment kar sakta hai, toh starting of unique element 
    // hamesha arr[0].first hi hoga qki abb arr sorted hai
    
    // now jaise mera pass (1 1 1 3) element hai toh mein kissi ek one jiski time sabse jayda hai usse 1 ji
    // ren dunga aur baki ko 2 kar dunga. so (1 2 2 3). 
    // Now here the use of prev come
    // qki abb mera pass option hai ki mein next element 2 ban doo and baki 2 ko 3 like this (1 2 3 3)
    // so prev mujhe yahi batata hai ki mera abb next consecutive element konsa hai
    // agr prev ki val arr[i].frist se choti hai matlab ki agr mein beech mein consecutive missing hai 
    // ya sare same elemnt set mein insert ho chuka hai abb just next elemnt hai 
    // toh mein bass highest time ko apne sum se minus kar deta hoo aur bachi hui cost ko add kar deta hoo 
    // and prev ko incrmnt

    ll prev=0;
    ll ans=0;

    for(ll i=0; i<n; i++){
        // now here we checck if our prev ki val arr[i].first se choti hais
        while(!s.empty() && prev<arr[i].first){
            auto it = s.end();
            --it;
            ll val = *it;
            temp -= val;
            ans += temp;
            s.erase(it);
            prev++;
        }
        // temp basically yeh batata ki kissi same numbers ko ek age shift karne ki kitna time lagta hai 
        // so hum hamesha temp ke sum se set ka last element minus kar deta hai qki ek element same reh sakta hai
        // and bachi hui ko sum mein add kar deta hai (matlab x no ko (x+1) banae mein temp time lga)
        prev = arr[i].first; // store the prev elemnt or ki konsa consective val par hoo 
        temp += arr[i].second; // add time of all no
        s.insert(arr[i].second); // insert into set so that we can max time at end
    }

    while(s.size()>1){
        auto it = s.end();
        --it;
        ll val = *it;
        temp -= val;
        ans += temp;
        s.erase(it);
    }

    cout<<ans<<endl;
    return 0;
}
