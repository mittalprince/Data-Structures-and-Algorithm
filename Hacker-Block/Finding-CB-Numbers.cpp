#include<iostream>
#include<vector>
#include<bitset>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int n;
string s;
bitset<17> visited;

bool isCBNumber(string s){
    ll number = stoll(s);
    if(number == 0|| number == 1) return false;

    int arr[10] = {2,3,5,7,11,13,17,19,23,29};

    for(int i=0; i<10; i++){
        if(number==arr[i])return true;
    }
    for(int i=0; i<10; i++){
        if(number%arr[i] == 0) return false;
    }
    return true;
}

bool isValid(int s, int e){
    for(int i=s; i<e; i++){
        if(visited[i]) return false;
    }
    return true;
}

int solve(){
    int ct=0;
    for(int k=1; k<=n; k++){
        for(int i=0; i<=n-k; i++){
            int j=i+k;
            string sub = s.substr(i, k);
            if(isCBNumber(sub) && isValid(i, j)){
                ct++;
                for(int l=i; l<j; l++){
                    visited[l]=1;
                }
            }
        }
    }
    return ct;
}
int main(){
    cin>>n;
    cin>>s;
    cout<<solve()<<endl;
    return 0;
}