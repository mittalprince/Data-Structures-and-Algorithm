#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

bool canPlace(vector<int>&arr, int k, int minDist){
    int total_placed=0;
    for(int i=0; i<arr.size()-1; i++){
        total_placed += (int)(arr[i+1]-arr[i])/minDist;
    }
    return (total_placed <= k);
}
double minmaxgasDist(vector<int>&arr, int k){
    int n=arr.size();
    double start=0, end=1e8;

    while(end-start > 1e-6){
        double mid = (start+end)/2;

        if(canPlace(arr, k, mid)){
            // i.e ki mein mid (min dist) par k sttaion ya usse kamm station place kar pa rha hoo
            // agr mera mid ke liye total_place == k i.e i can place so try to minimize this val and decr mid so e=mid
            // but when total_placed<k i.e ki agr mein mid (asume 1.005) par k nahi place kar paa rha tabhi total_place<k
            // then i must dec mid (i.e coose val less than 1.005) which can be done by e=mid
            end=mid;
        }
        else start=mid;
    }
    return start;
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    ip(arr, n);
    double ans = minmaxgasDist(arr, k);
    cout<<fixed<<setprecision(8)<<endl;
    cout<<(double)ans<<endl;
    return 0;
}