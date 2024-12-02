// https://leetcode.com/problems/check-if-n-and-its-double-exist/
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

bool checkIfExist(vector<int>& arr) {
    unordered_set<int> uset;
    for(int& i:arr){
        if(uset.count(2*i) || (!(i&1) && (uset.count(i/2))))
            return true;
        uset.insert(i);
    }
    return false;
}
/*
bool binarySearch (vector<int> &arr, int l, int r, int target)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == target)
            return true;
        else if (arr[m] > target)
            r = m - 1;
        else
            l = m + 1;
    }
    return false;
}

bool checkIfExist(vector<int>& arr) 
{
    sort(arr.begin(), arr.end());
    for (int pointer_one = 0; pointer_one < arr.size(); pointer_one++) {
        if ((arr[pointer_one] % 2 == 0) && arr[pointer_one] < 0) {
            if (binarySearch(arr, pointer_one + 1, arr.size() - 1, arr[pointer_one] / 2))
                return true; 
        }
        else {
            if (binarySearch(arr, pointer_one + 1, arr.size() - 1, 2 * arr[pointer_one]))
                return true;
        }
    }
    return false;
}
*/

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}