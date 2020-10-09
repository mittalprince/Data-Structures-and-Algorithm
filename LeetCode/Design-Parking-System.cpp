// https://leetcode.com/problems/design-parking-system/
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

class ParkingSystem {
public:
    int medium_capacity=0, big_capacity=0, small_capacity=0;
    int small_used=0, medium_used=0, big_used=0;
    
    ParkingSystem(int big, int medium, int small) {
        small_capacity=small;
        medium_capacity=medium;
        big_capacity=big;
    }
    
    bool addCar(int carType) {
        if(carType==3){
            small_used++;
            return  small_used<=small_capacity;
        }
        else if(carType==2){
            medium_used++;
            return  medium_used<=medium_capacity;
        }
        else{
            big_used++;
            return  big_used<=big_capacity;
        }
    }
};

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