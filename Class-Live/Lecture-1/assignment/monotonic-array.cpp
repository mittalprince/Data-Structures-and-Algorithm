#include<iostream>
#include<vector>
using namespace std;

bool isMonotonic(vector<int>& arr){
    int n = arr.size();
    int i=1, prev=arr[0];
    bool inc=true;

    while(i<n && arr[i]==prev){
        i++;
    }
    if(i==n) return true;
    if(prev>arr[i]) inc=false;
    prev = arr[i];
    i++;

    for(; i<n; i++){
        if(inc){
            if(prev>arr[i]) return false;
        }
        else{
            if(prev<arr[i]) return false;
        }
        prev = arr[i];
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    (isMonotonic(arr))?cout<<"true\n":cout<<"false\n";
    return 0;
}