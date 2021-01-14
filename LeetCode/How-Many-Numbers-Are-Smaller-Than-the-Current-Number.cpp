//https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define ip(arr, n)              \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];
#define ip1(arr, n)              \
    for (int i = 1; i <= n; i++) \
        cin >> arr[i];
#define op(arr, n)              \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << " ";
#define fstIO                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define debug(x) cout << x << "\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

vector<int> smallerNumbersThanCurrent(vector<int> &nums)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int freq[105] = {0};
    for (int i : nums)
    {
        freq[i]++;
    }

    for (int i = 1; i < 105; i++)
        freq[i] += freq[i - 1];

    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = nums[i] ? freq[nums[i] - 1] : 0;
    }
    return nums;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> arr(n);

    return 0;
}