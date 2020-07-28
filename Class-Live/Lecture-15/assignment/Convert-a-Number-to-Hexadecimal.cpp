#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

string toHex(int num) {
    if (num == 0)
        return string("0");
    unsigned uNum = num;
    string result;
    char chars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd',                             'e', 'f'};
    while (uNum > 0) {
        unsigned digit = uNum % 16;
        result = chars[digit] + result;
        uNum /= 16;
    }
    return result;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}