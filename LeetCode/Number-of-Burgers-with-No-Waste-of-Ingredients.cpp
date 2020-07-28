// https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/
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

vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
    if(tomatoSlices&1){
        return {};
    }

    int x = (tomatoSlices - 2*cheeseSlices)/2;
    int y = cheeseSlices-x;

    if(x<0 or y<0)return {};
    return {x,y};
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