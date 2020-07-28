#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<iterator>
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

/*
Logic: mein ek set mein jis jis din kissi bhi lake ko empty kar sakta hoo voh store kar lunga
then agr mujhe koi bhi aise lake milta hai jisme phela se rain hui hai toh mein check karta hoo
1. ki mein kisi bhi lake ko empty kar sakta hoo ya nahi, agr na toh return empty vec
otherwise mein check karunga ki jis din iss lake mein isse phela rain hui thi kya uska baad ka koi din hai
jisme mein lake ko empty kar sakta hoo ki nahi, iske liye jis din lake mein isse phela rain hui uska upper bound
set mein find krta hoo agr nahi milta koi din toh empty vec return 
otherwise I empty the lake, so in ans vector put val on this lake nad remove this from set
*/

vector<int> avoidFlood(vector<int>& rains) {
    set<int>kis_din_lake_ko_empty_kar_sakta_hoo;
    unordered_map<int, int>lake_mein_kis_din_rain_hui;

    int total_days=rains.size();
    vector<int>ans(total_days);
    for(int i=0; i<total_days; i++){
        int val = rains[i];
        if(val==0){
            ans[i]=1;
            kis_din_lake_ko_empty_kar_sakta_hoo.insert(i);
        }
        else{
            if(lake_mein_kis_din_rain_hui.count(val)){
                if(kis_din_lake_ko_empty_kar_sakta_hoo.empty()){
                    return vector<int>();
                }
                int kis_din_rain_hui = lake_mein_kis_din_rain_hui[val];
                set<int>::iterator f = kis_din_lake_ko_empty_kar_sakta_hoo.upper_bound(kis_din_rain_hui);
                if(f == kis_din_lake_ko_empty_kar_sakta_hoo.end()){
                    return vector<int>();
                }
                ans[*f]=val;
                kis_din_lake_ko_empty_kar_sakta_hoo.erase(*f);
            }
            lake_mein_kis_din_rain_hui[val]=i;
            ans[i]=-1;
        }
    }
    return ans;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}