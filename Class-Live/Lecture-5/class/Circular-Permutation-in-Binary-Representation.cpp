#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int greyCode(int n){
    return (n^(n>>1));
}
void reverse(vector<int>&arr, int s, int e){
    while(s<e){
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
    return;
}
vector<int> circularPermutation(int n, int start){
    vector<int>ans;
    for(int i=0; i<pow(2,n); i++){
        int x = greyCode(i);
        ans.push_back(x);
    }
    int k=0;
    for(k=0; k<ans.size(); k++){
        if(ans[k] == start){
            break;
        }
    }
    k = ans.size()-k;
    reverse(ans, 0, ans.size()-1);
    reverse(ans, 0, k-1);
    reverse(ans, k, ans.size()-1);

    return ans;
}

int main(){
    int n, start;
    cin>>n>>start;
    vector<int> res = circularPermutation(n, start);
    op(res, res.size());
    cout<<endl;
    return 0;
}