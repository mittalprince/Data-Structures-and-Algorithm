#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

// sort A and B vector
// Now traverse over A, and find whther its the next greater element of B
// if yes place this A[i], into ans vector at jth pos (index of B vec elemt, whose greater element is A[i])

vector<int> advantageCount(vector<int>& A, vector<int>& B) {
    int n=A.size();

    vector<pair<int, int>>vec;
    for(int i=0; i<n; i++){
        vec.push_back({B[i], i});
    }

    sort(A.begin(), A.end());
    sort(vec.begin(), vec.end());

    vector<int>ans(n, -1), x;
    int j=0;
    for(int i=0; i<n; i++){
        if(vec[j].first < A[i]){
            ans[vec[j].second] = A[i];
            j++;
        }
        else x.push_back(A[i]);
    }

    if(x.size() == 0) return ans;

    j=0;
    for(int i=0; i<ans.size(); i++){
        if(ans[i] == -1){
            ans[i] = x[j++];
        }
        if(j==x.size()) break;
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}