// https://www.interviewbit.com/problems/allocate-books/
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

bool isPossible(vector<int>&books, int total_students, int max_pages){
    int n = books.size();
    int curr_pages=0;
    int total_req_students=1;
    
    for(int i: books){
        if(curr_pages+i>max_pages){
            total_req_students++;
            curr_pages = i;
            
            if(total_req_students>total_students)return false;
        }
        else curr_pages += i;
    }
    
    return true;
}

int books(vector<int> &A, int B) {
    if(B>A.size())return -1;
    int s=0, e=0;
    for(int i: A){
        s = max(s, i);
        e += i;
    }
    
    int ans=-1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(isPossible(A, B, mid)){
            ans=mid;
            e=mid-1;
        }
        else s=mid+1;
    }
    return ans;
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