#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int func(int a, int b, int c, int x){
    return (a*x*x + b*x + c);
}

vector<int> sortTransformedArray(vector<int>&arr, int a, int b, int c){
    int n=arr.size();
    int left=0, right=n-1;
    vector<int>ans(n);
    int idx = (a>=0)?n-1:0;

    while(left <= right){
        if(a>=0){
            int opt1 = func(a,b,c,arr[left]);
            int opt2 = func(a, b, c, arr[right]);

            if(opt1 > opt2){
                ans[idx] = opt1;
                left++;
            }
            else{
                ans[idx] = opt2;
                right--;
            }
            idx--;
        }
        else{
            int opt1 = func(a, b, c, arr[left]);
            int opt2 = func(a, b, c, arr[right]);

            if (opt1 < opt2)
            {
                ans[idx] = opt1;
                left++;
            }
            else
            {
                ans[idx] = opt2;
                right--;
            }
            idx++;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    ip(arr,n);
    int a,b,c;
    cin>>a>>b>>c;
    vector<int> ans = sortTransformedArray(arr, a, b, c);
    op(ans, n);
    cout<<endl;
    return 0;
}