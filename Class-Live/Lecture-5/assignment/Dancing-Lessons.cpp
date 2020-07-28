#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class Pair{
    public:

    int left_idx, right_idx, val;
    Pair(int l, int r, int val):left_idx(l), right_idx(r), val(val){};

    // when we use user define dataype set we have to build our own comparator for soprting purpose 
    bool operator<(const Pair& b) const{
        if(val == b.val){
            return left_idx < b.left_idx;
        }
        return val < b.val;
    }
};

int main(){
    ll n;
    cin>>n;

    string str;
    cin>>str;

    ll arr[n];
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }               

    map<ll, ll>left, right;
    multiset<Pair>  s;

    for(ll i=1; i<n; i++){
        if(str[i] != str[i-1]){
            Pair obj(i-1, i, abs(arr[i]-arr[i-1]));
            s.insert(obj);
        }
        left[i] = i-1; // ith element ka left kya hai (obvious i > left[i])
        right[i-1] = i; // ith element ka right kya hai (obvios i< right[i])
    }          

    vector<pair<ll, ll> > ans;

    while(!s.empty()){
        Pair front = *s.begin();
        s.erase(s.begin());
        ll l = front.left_idx;
        ll r = front.right_idx;

        ans.push_back({l,r});

        // assume BBGG
        // we first del 1,2 (B,G) pair now after del it become BG
        // so left[l] exist karta hai and right[r] bhi and yeh dono index par diff char hai 
        // toh iski set mein daal doo
        if(left.find(l) != left.end() && right.find(r) != right.end() && str[left[l]] != str[right[r]]){
            Pair obj(left[l], right[r], abs(arr[left[l]] - arr[right[r]]));
            s.insert(obj);
        }

        // -------------------------------------------------------
        // assum we have BGBG
        // so in set we have insert 3 pair (BG, GB, BG)
        // now assume middle one (GB) gives least or at top of set
        // so we first remove it and now Pair of G with its adjacent left (BG (0-1)) become invalid
        // so we del this pair by checking if G ka koi hai and uski val G ke eqal nahi hai toh
        // uska pair bna hoga so we del it
        // same for right of B
        // why we handle this case
        
        if(left.find(l) != left.end() && str[l] != str[left[l]]){
            // left.fin(l) matlab iska left mein koi element hai ki nahi, agr ha toh uska index
            Pair obj(left[l], l, abs(arr[l]-arr[left[l]]));
            auto it = s.find(obj);
            if(it != s.end()) s.erase(it);
        }

        if(right.find(r) != right.end() && str[r] != str[right[r]]){
            // right.find(r) matlab iska right mein koi element hai ki nahi 
            Pair obj(r, right[r], abs(arr[r]-arr[right[r]]));
            auto it = s.find(obj);
            if(it != s.end()) s.erase(it);
        }

        // -------------------------------------------------------

        // update left and right map
        if(left.find(l) != left.end() && right.find(r) != right.end()){
            //left[i] denotes -> ith element ka left kya hai
            //right[i] denotes -> ith element ka right kya hai 
            right[left[l]] = right[r]; // toh jo l ka left tha that is left[i] uaka right abb r ka right hoga that is right[r] 
            left[right[r]] = left[l]; // toh abb right[r] ka left kya hai l ka left that if left[l]
        }

        else if(left.find(l) == left.end() && right.find(r) != right.end()){
            left.erase(right[r]); // if we erase the 0,1 index pair then left for 2 index do not exist now
            // as before this deletion left of 2 is 1 but now it's erased, so we erase left of 2 index
        }
        else if (left.find(l) != left.end() && right.find(r) == right.end()){
            right.erase(left[l]); // if we erase 4,5 index pair then right of 3 index do not exist as len is 6(indx 5 exist)
            // as berfore 3 right 4 tha but abb 3 last element ho gya toh uska right nahi rahga toh del it.
        }

    }

    cout<<ans.size()<<endl;
    for(ll i=0; i<ans.size(); i++){
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
    }
    return 0;
}