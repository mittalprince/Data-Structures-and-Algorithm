#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void count(map<int, int>& freq, vector<int>& arr){
    for(int n : arr){
        freq[n]++;
    }
}

vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
    map<int, int> freq;
    vector<int> res;
    
    count(freq, arr1);
    count(freq, arr2);
    count(freq, arr3);
    
    for(pair<int, int> p : freq){
        if(p.second == 3){
            res.push_back(p.first);
        }
    }
}

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    vector<int> arr1(a), arr2(b), arr3(c);
    ip(arr1, a);
    ip(arr2, b);
    ip(arr3, c);

    vector<int> res = arraysIntersection(arr1, arr2, arr3);
    for(int i: res) cout<<i<<" ";
    cout<<endl;
    return 0;
}