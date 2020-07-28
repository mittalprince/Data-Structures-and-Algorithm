#include<iostream>
#include<vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    int tc=1;
    int c,n;
    while(cin>>c){
        cin>>n;
        double avg=0.0;
        ll arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
            avg += arr[i];
        }
        avg = (double)avg/c;

        sort(arr, arr+n);

        ll r=n;
        ll l=r-2*c;

        cout<<"Set #"<<tc++<<endl;
        double imbalance_factor = 0.0;

        for(int i=0; i<c; i++){
            double chamber_sum = 0;
            cout<<" "<<i<<":";
            if(l>=0){
                chamber_sum += arr[l];
                cout<<" "<<arr[l];
            }
            if(r>0){
                cout<<" "<<arr[r-1];
                chamber_sum += arr[r-1];
            }
            l++;
            r--;
            imbalance_factor += abs(chamber_sum-avg);
            cout<<endl;
        }
        cout<<fixed<<setprecision(5)<<"IMBALANCE = "<<imbalance_factor<<endl<<endl;
    }
    return 0;
}