#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100005

vector<bool>isPrime(MAX+1, true);
map<ll, ll>m;

void sieve(){
    for(int i=2; i*i<MAX; i++){
        if(isPrime[i]){
            for(int j=i*i; j<MAX; j+= i){
                isPrime[j]=false;
            }
        }
    }
}

void sumOfFactors(){
    m[0]=0;
    m[1]=1;
    
    for(int i=2; i<MAX; i++){
        
        if(isPrime[i]){
            // m[i+1]=i;
            if(m.find(i+1) == m.end()){
                m[i+1] = i;
            }
            else{
                if(m[i+1] < i) m[i+1]=i;
            }
        }
        else{
            ll sum=0;
            for(int j=2; j*j<=i; j++){
                if(i%j == 0){
                    sum += (i/j);
                    if((i/j) != j){
                        sum += j;
                    }
                }
            }
            sum += i+1;
            if(m.find(sum) == m.end()){
                m[sum] = i;
            }
            else{
                if(m[sum] < i) m[sum]=i;
            }
            // m[sum]=i;
        }
    }
}
void solve(int n){
    // cout<<n<<endl;
    if(m.find(n) == m.end()){
        cout<<"-1\n";
    }
    else cout<<m[n]<<endl;
}

int main(){
    int n;
    sieve();
    sumOfFactors();
    cin>>n;
     while(n){
         solve(n);
         cin>>n;
    }
    return 0;
}