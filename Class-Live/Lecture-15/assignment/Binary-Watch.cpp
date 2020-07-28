#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int nb_ones(int n){
    int c = 0;
    while(n){
        c += (n&1);
        n >>= 1;
    }
    return c;
}
vector<string> readBinaryWatch(int num) {
    int maxhr = 11, maxmint = 59;
    vector<string> res;
    string time;
    for(int hr = 0 ; hr <= maxhr ; hr++){
        for(int mint = 0; mint <= maxmint ; mint++){
            if(nb_ones(hr) + nb_ones(mint) == num){
                time = to_string(hr) + ":";
                if(mint < 10) time += "0";
                time += to_string(mint);
                res.push_back(time);
            }
        }
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}