#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
    vector<vector<int>> ans(2, vector<int>(colsum.size(), 0));
    
    for (int i = 0; i < colsum.size(); ++i){
        if (colsum[i] == 2) { 
            --upper; --lower;
            ans[0][i] = 1;
            ans[1][i] = 1;
        }
        else if (colsum[i] == 1){
            if (upper >= lower){
                --upper;
                ans[0][i] = 1;
            }
            else{
                --lower;
                ans[1][i] = 1;
            }
        }
        else{
            ans[0][i] = 0;
            ans[1][i] = 0;
        }
    }

    if(upper != 0 || lower != 0)
        return {};
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> colsum(n);
    ip(colsum ,n);
    int upper, lower;
    cin>>upper>>lower;
    return 0;
}