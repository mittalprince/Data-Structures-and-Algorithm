#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void cs(vector<bool> &seive, int A){
    for(int i=2; i <= ceil(sqrt(A)); i++){
        if(seive[i] == true){
            for(int j=i*i; j<seive.size(); j+= i){
                seive[j]=false;
            }
        }
    }
}

vector<int> primesum(int A) {
    vector<int> ans(2, 0);
    vector<bool> seive(A, true);
    cs(seive, A);
    
    for(int i=2; i<A; i++){
        if(seive[i] && seive[A-i]){
            ans[0]=i;
            ans[1] = A-i;
            break;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}