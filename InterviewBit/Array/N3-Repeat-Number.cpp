// https://www.interviewbit.com/problems/n3-repeat-number/
#include<iostream>
#include<vector>
#include<climits>
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

int repeatedNumber(const vector<int> &A){
    int n=A.size();
    int c1=0, c2=0;
    int first=INT_MAX, second=INT_MAX;

    for(int i: A){
        if(i==first)c1++;
        else if(i==second)c2++;
        else if(c1==0){
            c1=1;
            first=i;
        }
        else if(c2==0){
            c2=1;
            second=i;
        }
        else{
            c1--;
            c2--;
        }
    }

    c1=0, c2=0;
    for(int i: A){
        if(i==first)c1++;
        else if(i==second)c2++;
    }
    if(c1>(n/3))return first;
    if(c2>(n/3))return second;

    return -1;
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