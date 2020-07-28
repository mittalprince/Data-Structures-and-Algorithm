// https://www.interviewbit.com/problems/triplets-with-sum-between-given-range/
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

int solve(vector<string> &B) {
    if(B.size()<3) return 0;
    vector<float> A;
    for(auto i : B){
        A.push_back(stof(i));
    }
    
    float a = A[0];
    float b = A[1];
    float c = A[2];
    
    for(int i=3;i<A.size();++i){
        if(a+b+c>1 && a+b+c<2)
            return 1;
    
        float temp = A[i];
    
        if(a+b+c>=2){
            if(a>b && a>c)
                a = temp;
            else if(b>c && b>a)
                b = temp;
            else
                c = temp;
        }
        else{
            if(a<b && a<c)
                a = temp;
            else if(b<c && b<a)
                b = temp;
            else
                c = temp;
        }
    }
    
    if(a+b+c>1 && a+b+c<2) return 1;
    
    return 0;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}