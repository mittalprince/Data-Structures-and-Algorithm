#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int CeilI(vector<int> &v, int l, int r, int key)
{
    while (r - l > 1)
    {
        int m = l + (r - l) / 2;
        if (v[m] >= key)
        {
            r = m;
        }
        else
            l = m;
    }
    return r;
}

int LIS(string &v)
{
    if (v.size() == 0)
        return 0;
    vector<int> tail(v.size(), 0);
    int len = 1;
    tail[0] = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] < tail[0])
        {
            tail[0] = v[i];
        }
        else if (v[i] > tail[len - 1])
        {
            tail[len++] = v[i];
        }
        else
            tail[CeilI(tail, -1, len - 1, v[i])] = v[i];
    }
    return len;
}
int solve(string arr)
{
    // Write your code here
    //    int n = arr.size();
    //    int dp[n];
    //    memset(dp, 1, sizeof dp);
    //    int ans = 1;
    //    for(int i=0; i<n; i++){
    //         int a= 1;
    //         for(int j=0; j<i; j++){
    //             if (arr[j]<arr[i]){
    //                 a = max(a, dp[j]+1);
    //             }
    //         }
    //         dp[i]=a;
    //         ans = max(ans, dp[i]);
    //    }
    return 26 - LIS(arr);
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t_i = 0; t_i < T; t_i++)
    {
        string s;
        cin >> s;

        int out_;
        out_ = solve(s);
        cout << out_;
        cout << "\n";
    }
}