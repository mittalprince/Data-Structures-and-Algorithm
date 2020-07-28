#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

bool lemonadeChange(vector<int>& bills) {
    int five=0, ten=0;
    int n=bills.size();
    
    for(int i: bills){
        if(i==5) five++;
        else if(i==10){
            ten++;
            if(five) five--;
            else return false;
        }
        else{
            if(five && ten){
                five--;
                ten--;
            }
            else if(five>2) five -=3;
            else return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    ip(arr, n);
    return 0;
}