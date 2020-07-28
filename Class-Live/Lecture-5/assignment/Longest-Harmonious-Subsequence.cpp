#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int findLHS(vector<int> &nums){
    map<int, int> m;
    for (auto i : nums)
    {
        m[i]++;
    }
    int ans = 0;
    for (auto i : m)
    {
        if (m.find(i.first - 1) != m.end())
        {
            ans = max(ans, i.second + m[i.first - 1]);
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    ip(arr, n);
    cout<<findLHS(arr)<<endl;
    return 0;
}