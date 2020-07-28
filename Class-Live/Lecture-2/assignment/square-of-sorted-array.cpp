#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<int> sortedSquares(vector<int> &A)
{
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
    int n;
    cin>>n;
    vector<int>arr(n);
    ip(arr, n);
    vector<int> ans = sortedSquares(arr);
    op(ans, n);
    cout<<endl;
    return 0;
}