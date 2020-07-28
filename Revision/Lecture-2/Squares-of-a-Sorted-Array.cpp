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

vector<int> sortedSquares(vector<int> &A){
    int n = A.size();
    int i = 0;
    while (i < n && A[i] < 0)
    {
        i++;
    }
    int left = i - 1, right = i;
    vector<int> ans;

    while (left >= 0 && right < n)
    {
        if (abs(A[left]) < A[right])
        {
            ans.push_back(A[left] * A[left]);
            left--;
        }
        else
        {
            ans.push_back(A[right] * A[right]);
            right++;
        }
    }

    while (left >= 0)
    {
        ans.push_back(A[left] * A[left]);
        left--;
    }
    while (right < n)
    {
        ans.push_back(A[right] * A[right]);
        right++;
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