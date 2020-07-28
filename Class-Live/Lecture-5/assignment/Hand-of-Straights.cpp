#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

bool isNStraightHand(vector<int>&arr, int w){
    int n=arr.size();
    if(n%w != 0) return false;
    if(w==1) return true;

    sort(arr.begin(), arr.end());
    while(!arr.empty()){
        int ct=1;
        int pos = arr.size()-1;
        int target = arr[pos]-1;
        pos--;

        while(ct<w){
            if(pos < 0) return false;

            if(arr[pos] == target+1) pos--;
            else if(arr[pos] == target){
                int temp = arr[pos];
                for(int i=pos; i<arr.size()-ct-1; i++){
                    arr[i] = arr[i+1];
                }
                arr[arr.size()-ct-1] = temp;
                target--;
                ct++;
                pos--;
            }
            else return false;
        }

        for(int i=0; i<w; i++){
            arr.pop_back();
        }
    }
    return true;
}

int main(){
    int n,w;
    cin>>n>>w;
    vector<int> arr(n);
    ip(arr, n);

    return 0;
}